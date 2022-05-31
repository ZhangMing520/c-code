1. 对象

> 在 Python 中，对象就是为 C 中的结构体在堆上申请的一块内存，一般来说，对象是不能被静态初始化的，并且也不能在栈空间上生存。
> 唯一的例外就是类型对象，Python 中所有的内建的类型对象（如整数类型对象，字符串类型对象）都是被静态初始化的。

> 一个对象一旦被创建，它在内存中的大小就是不变的了。这意味着那些需要容纳可变长度数据的对象只能在对象内维护一个指向一块可变大小的内存区域的指针

2. PyObject

> PyObject 是整个 Python 对象机制的核心

```cpp
// object.h
typedef struct _object {
	PyObject_HEAD
} PyObject;

#ifdef Py_TRACE_REFS
/* Define pointers to support a doubly-linked list of all live heap objects. */
#define _PyObject_HEAD_EXTRA		\
	struct _object *_ob_next;	\
	struct _object *_ob_prev;

#define _PyObject_EXTRA_INIT 0, 0,

#else
#define _PyObject_HEAD_EXTRA
#define _PyObject_EXTRA_INIT
#endif

/* PyObject_HEAD defines the initial segment of every PyObject. */
#define PyObject_HEAD			\
	_PyObject_HEAD_EXTRA		\
	Py_ssize_t ob_refcnt;		\
	struct _typeobject *ob_type;

// Visual Studio 的 release 模式下编译 Python 时候，不会定义符号 Py_TRACE_REFS
// PyObject 简化版本
typedef struct _object {
    // 引用计数
	Py_ssize_t ob_refcnt;
    // 指定一个对象类型的类型对象
    struct _typeobject *ob_type;
} PyObject;
```

```cpp
// [intobject.h]
typedef struct {
    PyObject_HEAD
    long ob_ival;
} PyIntObject;
```

3. PyVarObject

> ob_size 指明变长对象中一共容纳了多少个元素

> PyVarObject 实际上只是对 PyObject 的一个扩展而已。因此，对于任何一个 PyVarObject，其所占用的内存，开始部分的字节意义和 PyObject 是一样的。
> 换句话说，在 Python 内部，每一个对象都拥有相同的对象头部。这就使得在 Python 中，对象的引用变得非常的统一，我们只需要一个 PyObject * 指针就可以引用任意的一个对象。而不论该对象实际是一个什么对象。

```cpp
// [object.h]
#define PyObject_VAR_HEAD		\
	PyObject_HEAD			\
	Py_ssize_t ob_size; /* Number of items in variable part */

typedef struct {
	PyObject_VAR_HEAD
} PyVarObject;    
```

4. 类型对象 _typeobject

- 类型名，tp_name，主要是 Python 内部以及调试的时候使用；
- 创建该类型对象时分配内存空间大小的信息，即tp_basicsize, tp_itemsize
- 与该类型对象相关联的操作信息（就是诸如 tp_print 这样的许多的函数指针）

```cpp
typedef struct _typeobject {
	PyObject_VAR_HEAD
	const char *tp_name; /* For printing, in format "<module>.<name>" */
	Py_ssize_t tp_basicsize, tp_itemsize; /* For allocation */

	/* Methods to implement standard operations */

	destructor tp_dealloc;
	printfunc tp_print;
	getattrfunc tp_getattr;
	setattrfunc tp_setattr;
	cmpfunc tp_compare;
	reprfunc tp_repr;

	/* Method suites for standard classes */

	PyNumberMethods *tp_as_number;
	PySequenceMethods *tp_as_sequence;
	PyMappingMethods *tp_as_mapping;

	/* More standard operations (here for binary compatibility) */

	hashfunc tp_hash;
	ternaryfunc tp_call;
	reprfunc tp_str;
	getattrofunc tp_getattro;
	setattrofunc tp_setattro;

	/* Functions to access object as input/output buffer */
	PyBufferProcs *tp_as_buffer;

	/* Flags to define presence of optional/expanded features */
	long tp_flags;

	const char *tp_doc; /* Documentation string */

	/* Assigned meaning in release 2.0 */
	/* call function for all accessible objects */
	traverseproc tp_traverse;

	/* delete references to contained objects */
	inquiry tp_clear;

	/* Assigned meaning in release 2.1 */
	/* rich comparisons */
	richcmpfunc tp_richcompare;

	/* weak reference enabler */
	Py_ssize_t tp_weaklistoffset;

	/* Added in release 2.2 */
	/* Iterators */
	getiterfunc tp_iter;
	iternextfunc tp_iternext;

	/* Attribute descriptor and subclassing stuff */
	struct PyMethodDef *tp_methods;
	struct PyMemberDef *tp_members;
	struct PyGetSetDef *tp_getset;
	struct _typeobject *tp_base;
	PyObject *tp_dict;
	descrgetfunc tp_descr_get;
	descrsetfunc tp_descr_set;
	Py_ssize_t tp_dictoffset;
	initproc tp_init;
	allocfunc tp_alloc;
	newfunc tp_new;
	freefunc tp_free; /* Low-level free-memory routine */
	inquiry tp_is_gc; /* For PyObject_IS_GC */
	PyObject *tp_bases;
	PyObject *tp_mro; /* method resolution order */
	PyObject *tp_cache;
	PyObject *tp_subclasses;
	PyObject *tp_weaklist;
	destructor tp_del;

#ifdef COUNT_ALLOCS
	/* these must be last and never explicitly initialized */
	Py_ssize_t tp_allocs;
	Py_ssize_t tp_frees;
	Py_ssize_t tp_maxalloc;
	struct _typeobject *tp_prev;
	struct _typeobject *tp_next;
#endif
} PyTypeObject;
```

5. （整数）对象的创建

- 通过 Python C API 来创建
  - 泛型的API，或者称为AOL（Abstract Object Layer）。这类API都具有诸如 PyObject_*** 的形式，可以应用到任何 Python对象上。API内部会有一整套机制确定最终调用的函数是哪一个。
    ```cpp 
        PyObject* intObj = PyObject_New(PyObject, &PyInt_Type);
    ```
  - 与类型相关的API，或者称为COL（Concrete Object Layer）。通常只能作用在某一种类型的对象上，对于每一种內建对象，Python 都提供了这样的一组API。
    ```cpp
         PyObject* intObj = PyInt_FromLong(10);
    ```
- 通过类型对象 PyInt_Type
  ```cpp
  // 通过 PyInt_Type 创建了一个整数对象
  int(10)
  ```
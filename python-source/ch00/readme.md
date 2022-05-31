1. 内存管理接口概念上的简化

> 通常 Python 的源码中会使用 PyObject_GC_New PyObject_GC_Malloc PyMem_MALLOC PyObject_MALLOC等API。
> 只要坚持一个原则，凡是以 New 结尾的，都以 C++ 中的 new 操作符视之；凡是以 malloc 结尾的，都以 C 中的 malloc 操作符视之

```cpp
[PyString_FromString() in stringobject.c]
op = (PyStringObject *)PyObject_MALLOC(sizeof(PyStringObject) + size);
// 等效于
op = (PyStringObject *)malloc(sizeof(PyStringObject) + size);


[PyList_New() in listobject.c]
op = PyObject_GC_New(PyListObject, &PyList_Type);
// 等效于
op = new PyList_Type();

op->ob_item = (PyObject **) PyMem_MALLOC(nbytes);
// 等效于
op->ob_item = (PyObject **) malloc(nbytes);
```
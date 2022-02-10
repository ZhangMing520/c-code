#include <stdio.h>

/**
 * @brief while 循环
 *
 * 在C语言中，所有变量都必须先声明后使用，声明通常放在函数开始处的可执行语句之前
 *
 * %6.1f 表示格式化浮点数，6个数字宽，小数点后有1位
 * 
 * 5/9==0	5.0/9.0!=0	2个整数除法是取整的，如果需要准确请使用浮点数
 */
main()
{
	float fahr, celsius;
	int lower, upper, step;

	lower = 0;
	upper = 300;
	step = 20;

	fahr = lower;
	while (fahr <= upper)
	{
		celsius = 5 / 9 * (fahr - 32);
		printf("%3.0f %6.1f\n", fahr, celsius);
		fahr = fahr + step;
	}
}

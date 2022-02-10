#include <stdio.h>

/**
 * @brief for 循环
 * 
 * 一个通用规则：在所有可以使用某个类型的变量的值的地方，都可以使用该类型的更复杂的表达式
 */
main()
{
	int fahr;
	for (fahr = 300; fahr >= 0; fahr = fahr - 20)
	{
		printf("%3d %6.1f\n", fahr, 5.0 / 9.0 * (fahr - 32));
	}
}

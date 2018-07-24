//读入一个自然数n，计算其各位数字之和，用汉语拼音写出和的每一位数字。
//
//输入格式：每个测试输入包含1个测试用例，即给出自然数n的值。这里保证n小于10 ^ 100 ^ 。
//
//输出格式：在一行内输出n的各位数字之和的每一位，拼音数字间有1 空格，但一行中最后一个拼音数字后没有空格。
//
//输入样例：
//
//1234567890987654321123456789
//输出样例：
//
//yi san wu

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void main()
{
	char in_num[100];
	int sum = 0;
	char sum_py[10][5] = {
		"ling","yi","er","san","si","wu","liu","qi","ba","jiu"
	};

	printf("please input a number:\r\n");
	scanf_s("%s", in_num, 100);

	int i = 0;
	while (in_num[i] != '\0')
	{
		sum += ((int)in_num[i] - (int)'0');
		i++;
	}

/*

	for (int i = 0;in_num[i] != '\0';i++)
	{
		sum += ((int)in_num[i] - (int)'0');
	}
*/
	
	printf("sum = %d \r\n", sum);

	if (sum > 99)
	{
		printf("%s %s %s", sum_py[sum / 100], sum_py[(sum / 10) % 10], sum_py[sum % 10]);
	}
	else if (sum > 9 && sum < 100)
	{
		printf( "%s %s",sum_py[sum / 10],sum_py[sum % 10] );
	}
	else if (sum < 10)
	{
		printf("%s", sum_py[sum]);
	}
	system("pause");
}
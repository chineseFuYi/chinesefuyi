//����һ����Ȼ��n���������λ����֮�ͣ��ú���ƴ��д���͵�ÿһλ���֡�
//
//�����ʽ��ÿ�������������1��������������������Ȼ��n��ֵ�����ﱣ֤nС��10 ^ 100 ^ ��
//
//�����ʽ����һ�������n�ĸ�λ����֮�͵�ÿһλ��ƴ�����ּ���1 �ո񣬵�һ�������һ��ƴ�����ֺ�û�пո�
//
//����������
//
//1234567890987654321123456789
//���������
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
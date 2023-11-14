#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{

	char input[20] = {0};
	system("shutdown -s -t 300");
	printf("请输入题目答案，否则将在5分钟后关机\n");
	printf("已知椭圆C:x^2/a^2+y^2/b^2=1(a>b>0)，C的上顶点为A，两个焦点为F1,F2，离心率为1/2，过F1且垂直于AF2的直线与C交于D，E两点，且|DE|=6，则ΔADE的周长为\n");
again:
	scanf("%s", input);
	if (strcmp(input, "13") == 0)
	{
		system("shutdown -a");
	}
	else
	{
		printf("请注意时间哦！！！\n");
		goto again;
	}

	return 0;
}

// NOJ T036-b
//函数递归方法
#include <stdio.h>
void get_num(void);

int main(void)
{
    get_num();
    return 0;
}

void get_num()
{
    char ch = getchar();
    if (ch != '\n')
        get_num();
    if (ch != '\n')
        printf("%c", ch);
}
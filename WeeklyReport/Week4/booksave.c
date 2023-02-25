// booksave.c -- 在文件中保存结构中的内容
#include <stdio.h>
#include <string.h>
#define TSIZE 45
#define FMAX 5

struct film
{
    char title[TSIZE];
    int rating;
};
char *s_gets(char *st, int n);
int main()
{
    struct film movies[FMAX];
    int i = 0;

    puts("Enter 1st movie title:");
    while (i < FMAX && s_gets(movies[i].title, TSIZE) != NULL && movies[i].title[0] != '\0')
    {
        puts("Enter rating:");
        scanf("%d", &movies[i++].rating);
        while (getchar() != '\n')
            continue;
        puts("Enter next movie title:(Empty line to quite)");
    }
    if (i == 0)
        printf("No data entered.");
    else
        printf("Your movie list:\n");

    for (int j = 0; j < i; j++)
        printf("Movie: %10s Rating: %5d", movies[j].title, movies[j].rating);
    printf("Sayonala~");

    return 0;
}

char *s_gets(char *st, int n)
{
    char *ret_val;
    char *find;
    ret_val = fgets(st, n, stdin);
    if (ret_val) // 即非空
    {
        find = strchr(st, '\n');
        if (find) // 即非空
            *find = '\0';
        else
            while (getchar() != '\n')
                continue; // 处理剩余输入行
    }
    return ret_val;
}

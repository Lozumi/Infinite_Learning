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
    int j;

    puts("Enter 1st movie title:");
    while (i < FMAX && s_gets(movies[i].title, TSIZE) != NULL && movie[i].title[0] != '\0')
    {
    }
}

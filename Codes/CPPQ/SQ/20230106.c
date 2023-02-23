#include <stdio.h>

char *search(char *a, char *b)
{
    int flag = 1;
    int i, j;
    for (i = 0; a[i]; i++)
    {
        for (j = 0; b[j] && a[i + j]; j++)
        {
            if (a[j + i] == b[j])
                continue;
            flag = 0;
            break;
        }
        if (flag == 1)
            break;
    }
    if (flag == 1)
        return i;
    else
        return NULL;
}

char *inch(a)
{
    int i = 0;
    while ((*(a + i) = getchar()) != '\n')
        i++;
    *(a + i) = '\0';
    return a;
}

void inverse(a)
{
    char *p = a;
    while (*p)
    {
        p++;
    }
    p--;
    while (p != (a - 1))
    {
        printf("%c", *p);
        p--;
    }
}

int main()
{
    char *s;
    s = inch(s);
    inverse(s);
}
#include <stdio.h>

void greeting_omit(const char *);
int main(void)
{
    greeting_omit("");

    (void)getchar();
    return 0;
}
void greeting_omit(const char *name)
{
    printf(" hello world\n ");
}
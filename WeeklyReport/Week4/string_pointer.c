// 测试能够通过指向字符串的指针修改字符串
int main(void)
{
    const char *pt = "kunkun";
    pt[0] = 'i';
    return 0;
}
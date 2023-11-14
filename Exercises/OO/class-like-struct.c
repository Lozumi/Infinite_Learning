// 20230903 by Lozumi
// 利用结构体实现面向对象的类定义，在结构体内定义函数指针。
#include <stdio.h>

// 定义了名为Point的结构体，它包含了两个整型成员变量 x和 y，以及两个函数指针成员变量 pgetx 和 pgety
typedef struct
{
    int x, y;
    void (*pgetx)(int);
    void (*pgety)(int);
} Point;

/*  定义了 func 函数
    它接受一个指向 Point 结构体的指针作为参数
    在函数内部，通过调用 point->pgetx 函数指针来获取 x 的值，并将 point->x 作为参数传递给该函数
    通过调用 point->pgety 函数指针来获取 y 的值，并将 point->y 作为参数传递给该函数
*/
void func(Point *point)
{
    (point->pgetx)(point->x);
    (point->pgety)(point->y);
}

// 定义了一个名为 getx 的函数，它接受一个整型参数 x，并打印出 x 的值
void getx(int x)
{
    printf("x的值是%d\n", x);
}

// 同上
void gety(int y)
{
    printf("y的值是%d\n", y);
}

void main()
{
    // 创建了一个名为 Point1 的 Point 结构体实例，并设置了它的成员变量 x 和 y 的值
    Point Point1;
    Point1.x = 114514;
    Point1.y = 1919810;
    // 将 getx 函数和 gety 函数的地址分别赋值给 Point1 的成员变量 pgetx 和 pgety
    Point1.pgetx = getx;
    Point1.pgety = gety;
    // 调用 func 函数，将 &Point1 作为参数传递给它
    // 当 func 函数被调用时，它会分别调用 getx 和 gety 函数，打印出 Point1 的 x 和 y 的值
    func(&Point1);
}

// https://blog.csdn.net/jk_chen_acmer/article/details/79347003/
#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <list>
#include <vector>
#include <stack>
#include <queue>
#include <ctime>
#include <cstdlib>
// #include<windows.h>
#include <functional>
#define D long long
#define F double
#define MAX 0x7fffffff
#define MIN -0x7fffffff
#define mmm(a, b) memset(a, b, sizeof(a))
#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define pill pair<int, int>
#define for1(i, a, b) for (int i = a; i <= b; i++)
#define for2(i, a, b) for (int i = a; i >= b; i--)
#define ini(n) scanf("%d", &n)
#define inll(n) scanf("%lld", &n)
#define outisp(n) printf("%d ", n)
#define outllsp(n) printf("%lld ", n)
#define outiel(n) printf("%d\n", n)
#define outllel(n) printf("%lld\n", n)
using namespace std;
#define N 500100
#define MOD ((int)1e9 + 7)
#define random(a, b) (rand() % (b - a + 1) + a)
#define stop Sleep(2000)
#define CLS system("cls")
const string el = "\n";
const string elel = "\n\n";
const string sp = " ";
const string spsp = "  ";
const string tab = "\t";

int n;
pill x[N];
int tr[N];
D ans; // ans可能非常大，需要用long long

int lowbit(int i)
{
    return i & (-i);
}

void up(int a, int m)
{ // A[a]+=m
    while (a <= n)
    {
        tr[a] += m;
        a += lowbit(a);
    }
}

int query(int pos)
{
    int sum = 0;
    while (pos > 0)
    {
        sum += tr[pos];
        pos -= lowbit(pos);
    }
    return sum;
}

void process(void)
{
    ans = 0;
    // A数组就是此题树状数组所代表的数组
    // mmm(A,1);//所谓的A数组赋初值一
    ini(n);
    if (!n)
        return;
    for1(i, 1, n)
    {
        int mid;
        ini(mid);
        x[i] = mk(mid, i); // 保存在原数组中的位置
    }
    sort(x + 1, x + 1 + n); // 按照数的大小排序
    // 排序只是为了得到这些数的大小关系，重要的还是他们在原数组中是位置

    for1(i, 1, n)
    { // 因为A数组值为1，所以tr数组的值就等于tr[i]所代表的数的个数，lowbit(i)
        tr[i] = lowbit(i);
    }

    for1(i, 1, n)
    { // 对于排序后的数组从小到大过一遍
        // 把A[i]变成0表示已经访问过了，A[i]前面的（A[1]~A[i-1]）值还为1的个数，就是前面比它大的个数
        // 因为for循环是从小到大， 变0的顺序也是，所以A[i]变0后还没有变0的就是比它大的数
        up(x[i].se, -1); // 更新的是在原数组的位置
        // 1 to 0 , add -1
        ans += query(x[i].se - 1); // 从1到i-1中1的个数 ，到i也可以，反正A[i]是0
    }
    outllel(ans);
    process();
}

int main()
{
    process();
    return 0;
}
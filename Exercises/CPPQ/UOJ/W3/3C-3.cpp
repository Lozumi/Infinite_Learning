// UOJ W3-C
#include <iostream>
#include <vector>

std::vector<std::vector<int>> zFun(const std::vector<int> &a, int m)
{
    std::vector<std::vector<int>> result;

    // 递归截至条件
    if (m == 1)
    {
        for (int i = 0; i < a.size(); ++i)
        {
            result.push_back(std::vector<int>({a[i]}));
        }
        return result;
    }

    // 一般情况
    for (int i = 0; i < a.size(); ++i)
    {
        // 除去第一个元素之外的剩余元素进行选取(m-1)个
        std::vector<int> b = a;
        std::vector<int>::iterator it = b.begin();
        b.erase(it, it + i + 1); // 尤其要注意这里，排列不讲究顺序，前面已经出现过的，后面就不要考虑了，12已经考虑过了，那么21就不用考虑了
        std::vector<std::vector<int>> ret = zFun(b, m - 1);
        // 第一个元素+剩下的元素进行组装
        for (int j = 0; j < ret.size(); ++j)
        {
            std::vector<int> one;
            one.push_back(a[i]);
            for (int k = 0; k < ret[j].size(); ++k)
            {
                one.push_back(ret[j][k]);
            }
            result.push_back(one);
        }
    }
    return result;
}

int main()
{
    int n = 0, k = 0;
    std::vector<int> arr;
    std::cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        arr.push_back(i);
    }
    std::vector<std::vector<int>> ret = zFun(arr, k);
    for (std::vector<int> &v : ret)
    {
        for (int ele : v)
        {
            std::cout << ele << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}

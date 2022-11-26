
#include <iostream>
#include <vector>

using namespace std;

//求长度为number的组合
/*
  参数：
  v：基础元素集合
  cur_v：当前递归过程中的中间组合变量
  cur_index:当前递归处理到v中第几个元素了
  number:要求的组合的长度值
  result:用于保存组合结果
*/
template <class T>
void Combination_n(const vector<T> &v, vector<T> &cur_v, int cur_index, int number, vector<vector<T>> &result)
{

    if (number == 0)
    {
        result.push_back(cur_v);
        return;
    }

    if (cur_index >= v.size())
    {
        return;
    }

    cur_v.push_back(v[cur_index]);
    Combination_n(v, cur_v, cur_index + 1, number - 1, result);
    cur_v.pop_back();
    Combination_n(v, cur_v, cur_index + 1, number, result);
}

//求全组合，对于长度为n的v，组合的种类数一共有2^n-1种
/*
  参数:
  v是基础元素集合
  result用于保存所有组合结果
*/
template <class T>
void Combination(const vector<T> &v, vector<vector<T>> &result)
{
    if (v.empty())
    {
        return;
    }
    else if (v.size() == 1)
    {
        result.push_back(v);
        return;
    }

    //求不同长度的组合
    vector<int> temp_v;
    for (int i = 1; i <= v.size(); ++i)
    {
        Combination_n(v, temp_v, 0, i, result);
    }
}

int main(int argc, char *argv[])
{
    vector<int> v{1, 2, 3};
    vector<vector<int>> result;
    Combination(v, result);

    for (auto &a : result)
    {
        for (auto &b : a)
        {
            cout << b;
        }
        cout << endl;
    }
    return 0;
}
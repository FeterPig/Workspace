// Predicate / 谓词

// 谓词就是一个返回布尔值（bool）的仿函数或函数。
// 在 C++ 中，实现谓词主要有三种方式：普通函数、仿函数（函数对象） 和 Lambda 表达式。

#include <bits/stdc++.h>
using namespace std;

// 普通函数充当谓词
bool cmp(int val)
{
    return val > 5;
}
void test1()
{
    vector v{1, 2, 3, 4, 5, 6, 7};
    auto it = v.begin();

    it = find_if(it, v.end(), cmp);

    while (it != v.end())
    {
        cout << "找到值: " << *it << endl;
        it++;
        it = find_if(it, v.end(), cmp);
    }
}

// 仿函数充当谓词
class Cmp
{
public:
    bool operator()(int val1, int val2)
    {
        return val1 < val2;
    }
};
void test2()
{
    vector v{9, 1, 7, 8, 1, 3};
    sort(v.begin(), v.end(), Cmp());
    cout << "排序后: ";
    for_each(v.begin(), v.end(), [](int n)
             { cout << n << " "; });
    cout << endl;
}

// Lambda 表达式充当谓词
// Lambda 就是一个“随用随弃”的匿名函数。它在底层其实就是编译器帮你自动生成的一个仿函数类。
void test3()
{
    /**
     * []:   不捕获
     * [x]:  按值捕获x
     * [&x]: 按引用捕获x
     * [=]:  全体按值捕获
     * [&]:  全体按引用捕获
     */

    /**
     * [this]:  捕获当前this指针
     * [*this]: 捕获当前对象副本
     * [p = move(p)]: 处理智能指针等不可拷贝资源 (C++14)
     */
    
    vector v{9, 1, 7, 8, 6, 9};
    sort(v.begin(), v.end(), [](int a, int b)
         { return a < b; });

    // 完整形式要加 -> 后置返回类型, 实际应用中通常省略
    /*sort(v.begin(), v.end(), [](int a, int b) -> bool
         { return a < b; });*/

    cout << "排序后: ";
    for (auto &&i : v)
    {
        cout << i << " ";
    }
    cout << endl;
}

int main()
{
    test1();
    test2();
    test3();

    return 0;
}
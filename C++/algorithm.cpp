// 一些常用的算法函数

#pragma once
#include <algorithm>
#include <numeric>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/**
 * 排序 -> sort
 * 查找 -> find
 * 条件查找 -> find_if
 * 计数 -> count
 * 全员修改 -> transform
 * 反转 -> reverse
 * 求和 -> accumulate
 */

vector<int> v{9, 1, 2, 7, 7, 8};
vector<int> res(v.size());

int main()
{
    // sort 排序
    sort(v.begin(), v.end(), [](int a, int b) -> bool
         { return a > b; });

    //  find 查找
    auto it = find(v.begin(), v.end(), 7);

    // find_if 条件查找
    auto it = find_if(v.begin(), v.end(), [](int a) -> bool
                      { return a > 7; });

    // count 计数
    auto cnt = count(v.begin(), v.end(), 0);

    // transform 全员修改
    auto it = transform(v.begin(), v.end(), res.begin(), [](int a) -> int
                        { return a * 2; });

    // reverse 反转
    reverse(v.begin(), v.end());

    // accumulate 求和
    int sum = accumulate(v.begin(), v.end(), 0);

    return 0;
}
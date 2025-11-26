// 寻找小于等于 n 的所有素数

/*找素数的三种方法
 *1. 试除法
 *2. 埃氏筛
 *3. 线性筛*/

#include <bits/stdc++.h>
using namespace std;

int n;

vector<bool> arr_1(n + 1, true);
vector<bool> arr_2(n + 1, true);
vector<bool> arr_3(n + 1, true);

// 试除法 (O(N * sqrt(N)))
void func_1(int n)
{
    for (int i = 2; i <= n; i++)
    {
        for (int j = 2; j * j <= i; j++)
        {
            if (i % j == 0)
            {
                arr_1[i] = false;
                break;
            }
        }
    }
}

// 埃氏筛 (O(N * log(log N)))
void func_2(int n)
{
    for (int i = 2; i * i <= n; i++)
    {
        if (arr_2[i] == true)
        {
            for (int p = i * i; p <= n; p += i)
            {
                arr_2[p] = false;
            }
        }
    }
}

// 线性筛 (O(N))
void func_3(int n)
{
    vector<int> primes;

    for (int i = 2; i <= n; i++)
    {
        if (arr_3[i])
        {
            primes.push_back(i);
        }
        for (int p : primes)
        {
            // 只判断小于等于 n 的数字
            if (i * p > n)
            {
                break;
            }
            arr_3[i * p] = false;

            if (i % p == 0)
            {
                break;
            }
        }
    }
}

int main()
{
    cin >> n;

    arr_1[0] = false;
    arr_1[1] = false;

    arr_2[0] = false;
    arr_2[1] = false;

    arr_3[0] = false;
    arr_3[1] = false;

    return 0;
}
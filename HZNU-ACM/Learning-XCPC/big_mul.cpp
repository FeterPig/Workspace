// 高精度乘法

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string a, b;
    cin >> a >> b;

    int len_a = a.length();
    int len_b = b.length();

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    vector<int> sum(len_a + len_b, 0);

    for (int i = 0; i < len_a; i++)
    {
        for (int j = 0; j < len_b; j++)
        {
            sum[i + j] += (a[i] - '0') * (b[j] - '0');
        }
    }

    int add = 0;
    for (int i = 0; i < len_a + len_b; i++)
    {
        sum[i] += add;
        add = 0;
        if (sum[i] >= 10)
        {
            add = sum[i] / 10;
            sum[i] %= 10;
        }
    }

    bool flag = false;
    for (int i = len_a + len_b - 1; i >= 0; i--)
    {
        if (sum[i] != 0)
        {
            flag = true;
        }

        if (flag)
        {
            cout << sum[i];
        }
    }

    return 0;
}
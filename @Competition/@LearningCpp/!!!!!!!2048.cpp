#include <bits/stdc++.h>
using namespace std;

int main()
{
    int w, n;
    cin >> w >> n;
    vector<int[2]> point;
    vector<int> ans(n);
    for (int i = 0; i < n; i++)
    {
        int temp_1, temp_2;
        cin >> temp_1 >> temp_2;
        point.push_back({temp_1, temp_2});
    }

    bool have_i = false;
    for (int i = 0; i < n; i++)
    {
        if (point[i][0] == i)
        {
            have_i = true;
        }

        // 
    }
    if (have_i == false)
    {
        /* code */
    }
    

    return 0;
}
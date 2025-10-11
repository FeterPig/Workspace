#include <stdio.h>

int main()
{
    int T = 0;
    scanf("%d", &T);

    // T组测试样例
    for (int i = 0; i < T; i++)
    {
        // 一共带了n元
        int n = 0;
        // 想买k种金鱼
        int k = 0;
        // 总共有m种金鱼
        int m = 0;
        // 需要借的钱
        int sum = 0;

        scanf("%d %d %d", &n, &k, &m);

        // m组数据
        int arr[m];

        // 写入arr
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &arr[j]);
        }

        

    }
    return 0;
}
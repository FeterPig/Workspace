#include <stdio.h>

int max(int x, int y)
{
    return x > y ? x : y;
}

int main()
{
    int N, T;
    while (scanf("%d%d", &N, &T) != EOF)
    {
        if (N == 0 && T == 0)
        {
            return 0;
        }

        int yuyuedu_max = 0;
        for (int n_game = 0; n_game < N; n_game++)
        {
            // n_jieju种结局
            int n_jieju;
            scanf("%d", &n_jieju);
            // 每一个结局
            struct Jieju
            {
                int yuyuedu;
                int time;
            } jieju[n_jieju];

            for (int i = 0; i < n_jieju; i++)
            {
                scanf("%d", &jieju[i].yuyuedu);
            }
            for (int i = 0; i < n_jieju; i++)
            {
                scanf("%d", &jieju[i].time);
            }

            // 01背包!!!
            int dp[n_jieju + 1][T + 1];
            for (int i = 0; i <= n_jieju; i++)
            {
                for (int j = 0; j <= T; j++)
                {
                    dp[i][j] = 0;
                }
            }
            for (int i = 1; i <= n_jieju; i++)
            {
                for (int j = 1; j <= T; j++)
                {
                    if (jieju[i - 1].time > j)
                    {
                        dp[i][j] = dp[i - 1][j];
                    }
                    else
                    {
                        dp[i][j] = max(dp[i - 1][j], jieju[i - 1].yuyuedu + dp[i - 1][j - jieju[i - 1].time]);
                    }
                }
            }

            if (dp[n_jieju][T] > yuyuedu_max)
            {
                yuyuedu_max = dp[n_jieju][T];
            }
        }
        printf("%d\n", yuyuedu_max);
    }

    return 0;
}

// tmd重新写吧
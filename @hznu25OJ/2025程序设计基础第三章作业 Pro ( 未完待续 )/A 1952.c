// #include <stdio.h>
// #include <limits.h>

// // 判断是否为幸运数
// int is_xingyunshu(int num)
// {
//     while (1)
//     {
//         if (num % 10 != 4 && num % 10 != 7)
//         {
//             return 0;
//         }
//         else
//         {
//             num = num / 10;
//         }
//         if (num == 0)
//         {
//             return 1;
//         }
//     }
// }

// // 判断是否所有位之和为n
// int is_all_add_n(int num, int n)
// {
//     int add = 0;
//     while (1)
//     {
//         add += num % 10;
//         num = num / 10;
//         if (num == 0)
//         {
//             break;
//         }
//     }
//     if (add == n)
//     {
//         return 1;
//     }
//     else
//     {
//         return 0;
//     }
// }

// int main()
// {
//     int n = 0;
//     scanf("%d", &n);

//     int num = 0;
//     while (1)
//     {
//         num++;
//         if (is_xingyunshu(num) == 1 && is_all_add_n(num, n) == 1)
//         {
//             printf("%d", num);
//             break;
//         }
//         if (num == INT_MAX)
//         {
//             printf("%d", -1);
//             break;
//         }
//     }

//     return 0;
// }
//
// samples本地调试全都AC,一提交就是WA,我也不懂为啥一直不给过

// -------------枚举法------------
// ----------------------------------------
// -------------构造法------------

#include <stdio.h>

int is_add_n(int num, int n)
{
    int add = 0;
    while (1)
    {
        add += num % 10;
        num = num / 10;
        if (num == 0)
        {
            break;
        }
    }
    if (add == n)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    if (n == 0)
    {
        printf("-1\n");
        return 0;
    }

    long long int num = 0;
    int flag = -1;
    for (int i = 0; i < 2100000000; i++)
    {
        num += 4;
        flag = is_add_n(num, n);
        if (flag == 1)
        {
            printf("%lld", num);
            return 0;
        }

        num += 3;
        flag = is_add_n(num, n);
        if (flag == 1)
        {
            printf("%lld", num);
            return 0;
        }
        num = (num - 3) * 10;
    }

    printf("%d", -1);
    return 0;
}

TO_BE_CONTINUED
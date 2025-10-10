#include <stdio.h>
#include <limits.h>
#include <time.h> // 引入时间库

// 递归写法
int Fib_1(int n)
{
    if (n <= 2)
        return 1;
    else
        return Fib_1(n - 1) + Fib_1(n - 2);
}

// 迭代写法
int Fib_2(int n)
{
    int a = 1;
    int b = 1;
    int c = 1;

    while (n >= 3)
    {
        c = a + b;
        a = b;
        b = c;
        n--;
    }

    return c;
}

// 递归方法
/**
 * 见下文递推方法
 */

void time_1()
{
    clock_t start, end;

    double duration;

    start = clock();

    for (int n = 1; Fib_1(n) > 0; n++)
    {
        printf("%d ", Fib_1(n));
    }

    end = clock();

    duration = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\n递归方法运行时间: %lf 秒\n", duration);
}

// 迭代方法
void time_2()
{
    clock_t start, end;

    double duration;

    start = clock();

    for (int n = 1; Fib_2(n) > 0; n++)
    {
        printf("%d ", Fib_2(n));
    }

    end = clock();

    duration = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\n迭代方法运行时间: %lf 秒\n", duration);
}

// 递推方法
void time_3()
{
    clock_t start, end;

    double duration;

    start = clock();

    int arr[50] = {0};
    arr[1] = 1;
    arr[2] = 1;

    for (int n = 1; n < 47; n++)
    {
        if (n == 1 || n == 2)
        {
            printf("%d ", arr[n]);
        }
        else
        {
            arr[n] = arr[n - 1] + arr[n - 2];
            printf("%d ", arr[n]);
        }
    }

    end = clock();

    duration = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\n递推方法运行时间: %lf 秒\n", duration);
}

int main()
{
    // 调用封装后的递归计时函数
    time_1();
    time_2();
    time_3();

    return 0;
}
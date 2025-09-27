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
void timeRecursiveFib_1()
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

    printf("\n递归方法运行时间: %f 秒\n", duration);
}

// 迭代方法
void timeRecursiveFib_2()
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

    printf("\n迭代方法运行时间: %f 秒\n", duration);
}

int main()
{
    // 调用封装后的递归计时函数
    timeRecursiveFib_1();
    timeRecursiveFib_2();

    return 0;
}
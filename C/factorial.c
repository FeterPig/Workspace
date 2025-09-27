#include <stdio.h>

int factorial(int n)
{
    if (n <= 1)
        return 1;
    else
        return (n * factorial(n - 1));
}

int main()
{
    int n;
    printf("计算__的阶乘: ");
    scanf("%d", &n);
    printf("%d的阶乘是: %d", n, factorial(n));
    return 0;
}
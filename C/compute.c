#include <stdio.h>
#include <stdlib.h>

int Add(int a, int b)
{
    int sum = a + b;
    return sum;
}

int Subtract(int a, int b)
{
    int sum = a - b;
    return sum;
}

int Multiply(int a, int b)
{
    int sum = a * b;
    return sum;
}

int Divide(int a, int b)
{
    int sum = a / b;
    return sum;
}

int main()
{
    int a, b, choose, sum;
    printf("输入两个数字，以空格隔开：");
    scanf("%d %d", &a, &b);

    printf("请选择计算方式\n");
    printf("(1)加法 (2)减法 (3)乘法 (4)除法：");
    scanf("%d", &choose);

    switch (choose)
    {
    case 1:
        sum = Add(a, b);
        printf("%d + %d = %d", a, b, sum);
        break;
    case 2:
        sum = Subtract(a, b);
        printf("%d - %d = %d", a, b, sum);
        break;
    case 3:
        sum = Multiply(a, b);
        printf("%d × %d = %d", a, b, sum);
        break;
    case 4:
        sum = Divide(a, b);
        printf("%d ÷ %d = %d ... %d", a, b, sum, a % b);
        break;
    default:
        printf("输入错误，请重试！");
        break;
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

int Add(int x, int y)
{
    return x + y;
}

int Sub(int x, int y)
{
    return x - y;
}

int Mul(int x, int y)
{
    return x * y;
}

int Div(int x, int y)
{
    return x / y;
}

int menu()
{
    printf("************************************\n");
    printf("************** 计算器 **************\n");
    printf("************************************\n\n");
    // Sleep(500);
    printf("************************************\n");
    printf("************* 1. start *************\n");
    printf("************************************\n");
    printf("************* 2. exit **************\n");
    printf("************************************\n\n");

    int ret;
    printf("请选择 -> ");
    scanf("%d", &ret);
    return ret;
}

int menu_choice()
{
    printf("************************************\n");
    printf("******* 1. 加法 ***** 2. 减法 ******\n");
    printf("************************************\n");
    printf("******* 3. 乘法 ***** 4. 除法 ******\n");
    printf("************************************\n\n");

    int ret;
    printf("请选择 -> ");
    scanf("%d", &ret);
    return ret;
}

void compute(int (*func)(int x, int y), char *compute_char)
{
    int x = 0, y = 0;

    printf("请输入两个操作数: ");
    scanf("%d %d", &x, &y);

    printf("%d %s %d = %d\n\n", x, compute_char, y, func(x, y));
}

int main()
{
    while (1)
    {
        if (menu() != 1)
        {
            printf("执行错误!\n");
            exit(0);
        }

        // 函数指针数组
        int (*arr[4])(int, int) = {&Add, &Sub, &Mul, &Div};

        switch (menu_choice())
        {
        case 1:
            compute(arr[0], "+");
            break;

        case 2:
            compute(arr[1], "-");
            break;

        case 3:
            compute(arr[2], "×");
            break;

        case 4:
            compute(arr[3], "÷");
            break;

        default:
            printf("执行错误!\n");
            exit(0);
        }
    }
    return 0;
}
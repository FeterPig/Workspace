// 输入一个数字，判断它是不是素数

#include <stdio.h>

void isPrime(int num, int *result)
{
    if (num < 2)
    {
        goto end;
    }

    int i = 2, j = num - 1;
    while (i <= num / 2)
    {
        while (j >= i)
        {
            if (i * j == num)
            {
                *result = 0;
                goto end;
            }
            else
                j--;
        }
        i++;
        j = num - 1;
    }
    *result = 1;
end:
}

int main()
{
    int num = 0;
    int result = -1;

    printf("输入一个数字，判断它是不是素数：");
    scanf("%d", &num);

    isPrime(num, &result);

    switch (result)
    {
    case 1:
        printf("%d是素数", num);
        break;
    case 0:
        printf("%d不是素数", num);
        break;
    default:
        printf("程序错误，请重试！");
        break;
    }

    return 0;
}

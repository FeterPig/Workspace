#include <stdio.h>

int main()
{
    int i = 1; // 行数
    int j = 9; // 星号数
    int k = 0; // 空格数
    int count; // 计数变量

    while (i <= 5) // 实现多行
    {
        for (count = k; count > 0; count--) // 实现行内空格
        {
            printf(" ");
        }

        for (count = j; count > 0; count--) // 实现行内星号
        {
            printf("*");
        }

        printf("\n");

        k++;
        j -= 2;
        i++;
    }

    return 0;
}
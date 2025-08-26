// Next Step：用递归的方法改进成正序打印

#include <stdio.h>

void print(int num)
{
    if (num > 9)
    {
        print(num / 10);
    }
    printf("%d ", num % 10);
}


// 用递归的方法求解字符串长度

int count(char *str)
{
    if (*str != '\0')
    {
        return 1 + count(str++);
    }
    else
    {
        return 0;
    }
}

int main()
{
    int num = 0;
    char str[40];

    printf("请输入一段正整数：");
    scanf("%d", &num);
    print(num);

    printf("\n请输入一段字母: ");
    scanf("%s", str);
    printf("字母的个数是%d", count(str));

    return 0;
}
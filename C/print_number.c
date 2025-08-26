#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 声明函数
// int count(unsigned int);
void judge(const char *str);
int count(unsigned int);
void print(int, unsigned int);

int main()
{
    char str[40];
    unsigned int num = 0;
    printf("请输入一段正整数：");
    scanf("%s", str);
    if (str[0] == '0') // 判断是否以0开头
    {
        printf("数字不合法，程序退出！");
        exit(0);
    }
    else
    {
        judge(str);

        num = (unsigned int)strtoul(str, NULL, 10);
        // 将 str 转为 unsigned int 类型

        print(count(num), num);
        return 0;
    }
}

void judge(const char *str) // 判断数字长度是否合法
{
    const char *maxStr = "4294967295";
    if (strlen(str) > strlen(maxStr))
    {
        printf("数字不合法，程序退出！");
        exit(0);
    }
    if (strcmp(str, maxStr) > 0) // 长度相等时直接比较字符串
    {
        printf("数字不合法，程序退出！");
        exit(0);
    }
}

int count(unsigned int num) // 利用循环计数 判断数字位数
{
    int count = 0;
    while (num != 0)
    {
        num = num / 10; // 每次除以10，去掉最后一位
        count++;        // 计数加1
    }
    return count;
}

void print(int len, unsigned int num) // 从最后一位依次打印每一位数字
{
    for (int i = len; i > 0; i--)
    {
        printf("%u ", num % 10);
        num = num / 10;
    }
}

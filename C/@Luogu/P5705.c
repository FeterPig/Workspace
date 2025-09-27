/*
题目描述
输入一个不小于 100 且小于 1000，同时包括小数点后一位的一个浮点数，例如 123.4 ，要求把这个数字翻转过来，变成 4.321 并输出。

输入格式
一行一个浮点数

输出格式
一行一个浮点数
*/

#include <stdio.h>

int main()
{
    float init;
    scanf("%f", &init);
    int int_init = (int)(init * 10);
    int a = int_init % 10;
    int b = int_init / 10 % 10;
    int c = int_init / 100 % 10;
    int d = int_init / 1000;
    int sum = a * 1000 + b * 100 + c * 10 + d;
    float float_sum = sum / 1000.0;
    printf("%.3f", float_sum);
    return 0;
}
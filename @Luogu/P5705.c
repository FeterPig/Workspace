#include <stdio.h>

int main()
{
    float init;
    scanf("%d", &init);
    int int_init = (int)(init * 10);
    int a = int_init % 10;
    int b = int_init / 10 % 100;
    int c = int_init / 100 % 1000;
    int d = int_init / 1000;
    int sum = a * 1000 + b * 100 + c * 10 + d;
    float float_sum = sum/1000;
    printf("%.3f",float_sum);
    return 0;
}
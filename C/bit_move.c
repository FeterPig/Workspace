#include <stdio.h>

int main()
{
    int a = -7;
    int b = a >> 1;

    printf("a = %d\n", a);
    printf("b = %d\n", b);

    /**
     * a = -7
     * b = -4
     * 说明gcc编译器使用的是算术右移
     */

    return 0;
}
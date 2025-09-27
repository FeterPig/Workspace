#include <stdio.h>

int main()
{
    int a = 1;
    int b = 2;
    int c = 3;

    /**
     * 理解为 int* arr[3] 更好
     * 创建的是数组arr
     * 数组的内容的类型是int*
     */
    int *arr[3] = {&a, &b, &c};

    /**
     * arr:     首元素的地址    &&a
     * *arr:    首元素的内容    *(&&a)==&a
     * arr[0]:  首元素的内容    &a
     * *arr[0]: 首元素指向的值  *&a==a
     */
    printf("%p\n", arr); // 00000069129FF750

    printf("%p\n", *arr); // 00000069129FF77C

    printf("%p\n", arr[0]); // 00000069129FF77C

    printf("%d\n", **arr); // 1

    printf("%d\n\n", *arr[0]); // 1

    return 0;
}
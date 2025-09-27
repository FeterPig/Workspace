#include <stdio.h>

// 冒泡排序
void bubble_sort(int arr[], int sz)
// 函数参数中的int arr[]看起来像数组，
// 但编译器会把它解析为int* arr（整数指针）。
// 即使你写成int arr[10]，
// 编译器也会忽略这个长度，仍然当作int *arr处理。
// 指针和数组在很多场景下可以互换使用

// 修正: 平时正常写代码时直接写成 int arr[10] 即可
// 理解为用相应的数组接收, 不用过于深究

{
    // 一次冒泡排序
    for (int i = 0; i < sz - 1; i++)
    {
        // 单趟冒泡排序
        for (int j = 0; j < sz - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    printf("\n冒泡排序后的数组是: ");

    for (int k = 0; k < sz; k++)
    {
        printf("%d ", arr[k]);
    }
}

int main()
{
    int arr[10] = {7, 8, 6, 9, 5, 3, 4, 0, 2, 1};

    // 数组元素个数
    int sz = sizeof(arr) / sizeof(arr[0]);

    printf("排序前的原始数组是: ");

    for (int i = 0; i < sz; i++)
    {
        printf("%d ", arr[i]);
    }

    // 传入arr[10]首元素的地址
    bubble_sort(arr, sz);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int i; // 第几个数字
    int j; // 遍历
    int k; // 循环控制

    do
    {
        printf("要找第几个数字？");
        scanf("%d", &i);
        printf("第%d个数字是%d\n", i, arr[i - 1]);

        printf("是否展示全体数字？(1/0)"); // *
        scanf("%d", &k);

        if (k == 1)
        {
            for (j = 0; j < 9; j++)
            {
                printf("%d ", arr[j]);
                if (j == 8)
                {
                    printf("\n");
                }
            }
        }

    } while ((k != 1) && (k != 0)); // 若*处输入其他字符，则重新运行

    return 0;
}
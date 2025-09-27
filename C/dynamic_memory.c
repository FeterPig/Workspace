#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * 动态类型分配
 * alloc: 分配;分配内存;内存分配;申请内存;
 *
 * malloc: 申请一块连续的指定大小的内存块区域
 * calloc: 分配num个长度为size的连续空间并初始化
 *
 * realloc: 扩容成新的内存大小 (与前面的函数搭配使用)
 * free:    释放内存 (与前面的函数搭配使用)
 */

void _malloc()
{
    int *p = (int *)malloc(40);

    if (p == NULL)
    {
        printf("%s", strerror(errno));
        // return 1;
    }

    int *pn = (int *)realloc(p, 80);
    if (pn != NULL)
    {
        p = pn;
    }
    else if (pn == NULL)
    {
        // 扩容失败
        printf("%s", strerror(errno));
    }

    printf("%p\n", p);

    free(p);
    p = NULL;
}

void _calloc()
{
    int *p = (int *)calloc(10, 4);

    if (p == NULL)
    {
        printf("%s", strerror(errno));
        // return 1;
    }

    int *pn = (int *)realloc(p, 80);
    if (pn != NULL)
    {
        p = pn;
    }
    else if (pn == NULL)
    {
        // 扩容失败
        printf("%s", strerror(errno));
    }

    for (int i = 0; i < 10; i++)
    {
        printf("%d ", *(p + 1));
    }
    printf("\n");

    free(p);
    p = NULL;
}

int main()
{
    _malloc();
    _calloc();

    return 0;
}
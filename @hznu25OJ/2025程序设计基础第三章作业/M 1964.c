#include <stdio.h>

int main()
{
    int a, b, c; // 年月日
    scanf("%d %d %d", &a, &b, &c);
    const int second_month = a % 4 == 0 ? 29 : 28; // 平年二月28,润年二月29

    return 0;
}

TO_BE_CONTINUED
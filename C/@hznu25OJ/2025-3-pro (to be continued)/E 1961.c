#include <stdio.h>
!!!!!!!!!!自己写一遍;
int main()
{

    int n, x = 0;
    scanf("%d", &n);

    while (n)
    {
        if (n % 10 == 4 || n % 10 == 7)
        {
            x = x + 1;
            n = n / 10;
        }
        else
            break;
    }

    /*
        获取n中4和7的个数，记为x
    */

    while (x)
    {
        if (x % 10 == 4 || x % 10 == 7)
            x = x / 10;
        else
            break;
    }

    /*
        判断x是否由4或7组成
    */

    if (n == 0 && x == 0)
        printf("YES");
    else
        printf("NO");

    return 0;
}
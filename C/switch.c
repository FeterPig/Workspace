#include <stdio.h>
#include <stdlib.h>

int main()
{
    int choose;

    while (1)
    {
        printf("好好学习? (1/0)");
        scanf("%d", &choose);

        switch (choose)
        {
        case 1:
            printf("恭喜你！\n");
            break;
        case 0:
            printf("继续努力！\n");
            break;
        default:
            break;
        }
    }

    return 0;
}
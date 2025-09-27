#include <stdio.h>

enum Week
{
    Monday = 1,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday,
    Sunday
};

int main()
{
    printf("%d\n", Monday);
    printf("%d\n", Tuesday);
    printf("%d\n", Wednesday);
    printf("%d\n", Thursday);
    printf("%d\n", Friday);
    printf("%d\n", Saturday);
    printf("%d\n", Sunday);
    return 0;
}

/**
 * 自定义类型
 * struct: 结构体
 * int:30: 位段
 * enum:   枚举
 * union:  联合体
 */ 
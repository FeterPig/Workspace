#include <stdio.h>

int main()
{
    // 0x00 00 00 01
    int a = 1;

    // 取第一个字节
    char res = *(char *)&a;

    // 无论大小端，CPU 都会从低地址开始依次读取字节，只是解析这些字节为数值时的顺序不同。
    if (res == 1)
    {
        //0x01 00 00 00
        printf("小端字节序");
    }
    else
    {
        //0x00 00 00 01
        printf("大端字节序");
    }

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i = 0;
    while (i < 10)
    {
        static int j = 0;
        j++;
        printf("%d ", j);
        i++;
    }

    // printf("%d ", j);

    // 报错：“j”未被定义，说明static仅延长变量生命周期，不改变作用域
    // 生命周期：单次循环 -> 程序结束
    // 作用域：局部变量 -> 局部变量（未改变）
    // *连接属性：外部链接属性 -> 内部链接属性

    return 0;
}
/*
题目描述
学校和 yyy 的家之间的距离为 s 米，而 yyy 以 v 米每分钟的速度匀速走向学校。

在上学的路上，yyy 还要额外花费 10 分钟的时间进行垃圾分类。

学校要求必须在上午 8:00 到达，请计算在不迟到的前提下，yyy 最晚能什么时候出门。

由于路途遥远，yyy 可能不得不提前一点出发，但是提前的时间不会超过一天。

输入格式
一行两个正整数 s,v，分别代表路程和速度。

输出格式
输出一个 24 小时制下的时间，代表 yyy 最晚的出发时间。

输出格式为 HH:MM，分别代表该时间的时和分。必须输出两位，不足前面补 0。
*/

#include <stdio.h>

int main()
{
    int s = 0; // 家距离学校 s 米
    int v = 0; // 速度 v 米每分钟
    const int ddl = 8 * 60 - 10;
    scanf("%d %d", &s, &v);
    float f_min = s / v;
    int i_min; // 提前多少分钟离开

    // 下面判断是否有小数部分, 若有则进位
    if (f_min - (int)f_min != 0)
    {
        i_min = (int)f_min + 1;
    }
    else
    {
        i_min = (int)f_min;
    }

    int s_time = ddl - i_min; // 在多少分钟时离开
    if (s_time < 0)
    {
        s_time = s_time + 24 * 60;
    }
    int s_hour = s_time / 60;   // 在第几个小时离开
    int s_minute = s_time % 60; // 在多少分时离开

    char time[5] = {' ', ' ', ':', ' ', ' '};
    if (s_hour < 10)
    {
        time[0] = (char)0;
        time[1] = (char)s_hour;
    }
    else
    {
        time[0] = (char)s_hour / 10;
        time[1] = (char)s_hour % 10;
    }
    if (s_minute < 10)
    {
        time[3] = (char)0;
        time[4] = (char)s_minute;
    }
    else
    {
        time[3] = (char)s_minute / 10;
        time[4] = (char)s_minute % 10;
    }

    for (size_t i = 0; i < 5; i++)
    {
        printf("%c", time[i]);
    }

    return 0;
}
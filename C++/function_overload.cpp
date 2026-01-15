// 函数的重载

#include <iostream>
using namespace std;

void func()
{
    cout << "未传入参数" << endl;
}
void func(int a)
{
    cout << "传入一个参数 " << "x=" << a << endl;
}
void func(int a, int b)
{
    cout << "传入两个参数 " << "x=" << a << " y=" << b << endl;
}

int main()
{
    int x = 10, y = 20;

    func();
    func(x);
    func(x, y);

    return 0;
}
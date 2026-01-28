// 函数对象 / 仿函数 / 重载小括号

#include <iostream>
using namespace std;

class MyPrint
{
private:
    int cnt = 0;

public:
    void operator()(string test)
    {
        cout << test << endl;
        this->cnt++;
        cout << "已打印" << this->cnt << "次" << endl;
    }
};

void doPrint(MyPrint arg_test, string str)
{
    for (int i = 0; i < 10; i++)
    {
        arg_test(str);
    }
}

int main()
{
    // 匿名对象: 短效生命周期
    doPrint(MyPrint(), "Hello world!");

    return 0;
}
#include <iostream>
using namespace std;

int a = 1, b = 1;

class Person
{
public:
    string name_;
    int age_;

public:
    Person(string name, int age) : name_(name), age_(age) {}
} p1{"张三", 18}, p2{"李四", 20};

// 该模板函数无法处理Person的比较
template <typename T>
bool myCmp(const T &a, const T &b)
{
    if (a == b)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// 利用具体化的Person重载模板函数
// 模板全特化, 这里本质上还是模板函数, 而非普通函数
template <>
bool myCmp(const Person &a, const Person &b)
{
    if (a.name_ == b.name_ && a.age_ == b.age_)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    cout << myCmp(a, b) << endl;
    cout << myCmp(p1, p2) << endl;

    return 0;
}
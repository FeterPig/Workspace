// 重载自增运算符

#include <iostream>
using namespace std;

class MyInteger
{
private:
    int num_;

public:
    MyInteger() : num_(0) {}

    friend ostream &operator<<(ostream &os, const MyInteger &my_integer);

    // 重载前置自增运算符
    MyInteger &operator++() // 使用引用&, 确保多次++时对同一对象进行操作
    {
        this->num_++;
        return *this;
    }

    // 重载后置自增运算符
    MyInteger operator++(int) // 使用int占位符, 代表后置自增
    {
        MyInteger tmp = *this;
        this->num_++;
        return tmp;
    }
};

// 重载左移运算符
ostream &operator<<(ostream &os, const MyInteger &my_integer)
{
    os << my_integer.num_;
    return os;
}

int main()
{
    MyInteger my_int;
    cout << ++my_int << endl;
    cout << my_int++ << endl;

    return 0;
}
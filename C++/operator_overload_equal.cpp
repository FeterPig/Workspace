// 重载关系运算符

#include <iostream>
using namespace std;

class Person
{
private:
    int arg1_;
    int arg2_;

public:
    friend void test(const Person &p1, const Person &p2);

    Person(int arg1, int arg2);
    ~Person();

    bool operator==(const Person &p) const;
};

Person::Person(int arg1, int arg2) : arg1_(arg1), arg2_(arg2) {}
Person::~Person() {}

bool Person::operator==(const Person &p) const
{
    return this->arg1_ == p.arg1_ && this->arg2_ == p.arg2_;
}

void test(const Person &p1, const Person &p2)
{
    if (p1 == p2)
    {
        cout << "(" << p1.arg1_ << "," << p1.arg2_ << ") = (" << p2.arg1_ << "," << p2.arg2_ << ")";
    }
    else
    {
        cout << "(" << p1.arg1_ << "," << p1.arg2_ << ") != (" << p2.arg1_ << "," << p2.arg2_ << ")";
    }
}

int main()
{
    int num1, num2;

    cout << "请输入第一对数据: ";
    cin >> num1 >> num2;
    Person p1(num1, num2);

    cout << "请输入第二对数据: ";
    cin >> num1 >> num2;
    Person p2(num1, num2);

    test(p1, p2);

    return 0;
}
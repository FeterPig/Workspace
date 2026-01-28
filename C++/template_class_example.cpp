#include <iostream>
#include <string>
using namespace std;

template <typename NameType, typename AgeType>
class Person
{
public:
    NameType name_;
    AgeType age_;
    Person(NameType name, AgeType age) : name_(name), age_(age) {}
    void test()
    {
        cout << "Name: " << this->name_ << endl
             << "Age: " << this->age_ << endl;
    }
};

int main()
{
    // Person<string, int> p1{"Faker", 25};
    // Person<int, char> p2{91, 'c'};

    // C++17 新特性: 类模板参数推导
    Person p1{"Faker", 25};
    Person p2{91, 'c'};

    p1.test();
    p2.test();

    return 0;
}
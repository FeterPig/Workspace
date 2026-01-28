// 重载赋值运算符

/**
 * 三大元法则
 * 如果你发现你的类需要手动实现以下三个函数中的任意一个，那么你几乎一定也需要手动实现剩下的两个。
 * 这三个函数分别是：析构函数、拷贝构造函数、赋值运算符重载
 */

#include <iostream>
#include <string>
using namespace std;

class Student
{
private:
    int id_;
    string name_;
    int *score_;

public:
    Student(int, string, int, int, int);
    ~Student();
    Student(const Student &);
    Student &operator=(const Student &);
};

Student::Student(int id, string name, int arg1, int arg2, int arg3) : id_(id), name_(name)
{
    this->score_ = new int[3];

    this->score_[0] = arg1;
    this->score_[1] = arg2;
    this->score_[2] = arg3;
}

// 析构函数
Student::~Student()
{
    if (this->score_ != nullptr)
    {
        delete[] this->score_;
        this->score_ = nullptr;
    }
}

// 拷贝构造函数
Student::Student(const Student &other) : id_(other.id_), name_(other.name_)
{
    this->score_ = new int[3];

    if (other.score_ != nullptr)
    {
        this->score_[0] = other.score_[0];
        this->score_[1] = other.score_[1];
        this->score_[2] = other.score_[2];
    }
}

// 赋值运算符重载
Student &Student::operator=(const Student &other)
{
    if (this == &other)
    {
        return *this;
    }

    this->score_[0] = other.score_[0];
    this->score_[1] = other.score_[1];
    this->score_[2] = other.score_[2];

    return *this;
}

int main()
{
    Student s1(1, "张三", 30, 40, 50), s2(2, "李四", 80, 90, 100);

    s1 = s2;
    Student s3 = s1;

    return 0;
}
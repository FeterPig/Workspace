// 重载等号

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
};

Student::Student(int id, string name, int arg1, int arg2, int arg3) : id_(id), name_(name)
{
    score_ = new int[3];
    score_[0] = arg1;
    score_[1] = arg2;
    score_[2] = arg3;
}

Student::~Student()
{
    if (score_ != NULL)
    {
        delete[] score_;
        score_ = NULL;
    }
}

int main()
{
    Student s1(1, "张三", 30, 40, 50), s2(2, "李四", 80, 90, 100);
    return 0;
}
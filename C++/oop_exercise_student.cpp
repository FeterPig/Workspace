// 设计一个学生类, 属性有姓名和学号, 可以给姓名和学号赋值, 可以显示学生的姓名和学号

#include <iostream>
#include <string>
using namespace std;

class Student
{
    // 解决形参名与成员变量名重名的三种方法
private:
    // 第一种: 成员变量加下划线后缀
    // string name_;
    string name;
    string id;

public:
    void setName(string name)
    {
        // 第二种: 使用this->成员变量
        this->name = name;
    }
    void setID(string id)
    {
        // 第三种: 使用作用域解析符::
        Student::id = id;
    }
    string showName()
    {
        return this->name;
    }
    string showID()
    {
        return this->id;
    }
};

int main()
{
    int choice_1;
    int choice_2;

    Student stu;

    do
    {
        cout << "设置/查询学生信息/退出 (1/2/0): ";
        cin >> choice_1;

        if (choice_1 == 1)
        {
            cout << "设置学生姓名/学号 (1/2): ";
            cin >> choice_2;

            if (choice_2 == 1)
            {
                string set_name;
                cout << "请输入学生姓名: ";
                cin >> set_name;
                stu.setName(set_name);
            }
            else if (choice_2 == 2)
            {
                string set_id;
                cout << "请输入学生学号: ";
                cin >> set_id;
                stu.setID(set_id);
            }
        }
        else if (choice_1 == 2)
        {
            cout << "查询学生姓名/学号 (1/2): ";
            cin >> choice_2;

            if (choice_2 == 1)
            {
                string show_name = stu.showName();
                cout << "学生的姓名为: " << show_name << endl;
            }
            else if (choice_2 == 2)
            {
                string show_id = stu.showID();
                cout << "学生的学号为: " << show_id << endl;
            }
        }
    } while (choice_1 != 0);

    return 0;
}
#include <iostream>
#include <fstream>
using namespace std;

fstream ioFile;

struct Person
{
    char name_[20];
    int age_;
} p1{"张三", 18}, p2;

void isOpen()
{
    if (!ioFile.is_open())
    {
        cout << "文件打开失败！" << endl;
        exit(1);
    }
}

void outLog()
{
    // 写入日志
    ioFile.write((const char *)&p1, sizeof(p1));
}

void inLog()
{
    // 清理状态并重置文件指针
    ioFile.clear();
    ioFile.seekg(0, ios::beg);

    // 读取日志
    ioFile.read((char *)&p2, sizeof(p2));
    cout << "Name: " << p2.name_ << endl;
    cout << "Age: " << p2.age_ << endl;
}

int main()
{
    ioFile.open("file_binary.bin", ios::out | ios::in | ios::app | ios::binary);

    isOpen();

    cout << "文件打开成功！" << endl;

    outLog();
    inLog();

    ioFile.close();

    return 0;
}
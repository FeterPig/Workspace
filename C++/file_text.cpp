// （i/o是相对于程序来说的）

/**
 * ifstream 只读：将文件内容读入程序。
 * ofstream 只写：将程序数据写入文件。
 * fstream  读写：同时具备读和写的功能。
 */

/**
 * ios::in     打开进行读取（ifstream 默认）。
 * ios::out    打开进行写入（ofstream 默认，会覆盖原文件）。
 * ios::app    追加模式(Append)，新内容写在文件末尾，不覆盖。
 * ios::trunc  截断模式(Truncate)，如果文件存在，先清空内容。
 * ios::binary 以二进制方式打开（默认是文本模式）。
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <ctime>
using namespace std;

fstream ioFile;

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
    // 获取时间
    time_t t = time(nullptr);
    tm *arg_tm = localtime(&t);

    // 写入日志
    ioFile << put_time(arg_tm, "[%Y/%m/%d][%H:%M:%S]") << "：\"" << "日志信息" << "\"" << endl;
}

void inLog()
{
    // 清理状态并重置文件指针
    ioFile.clear();
    ioFile.seekg(0, ios::beg);

    // 统计日志条数
    string tmp;
    int cnt = 0;
    while (getline(ioFile, tmp))
    {
        cnt++;
    }

    // 输出统计数据
    cout << "当前共有" << cnt << "条日志" << endl;
}

int main()
{
    ioFile.open("file_text.log", ios::out | ios::in | ios::app);

    isOpen();

    cout << "文件打开成功！" << endl;

    outLog();
    inLog();

    ioFile.close();

    return 0;
}
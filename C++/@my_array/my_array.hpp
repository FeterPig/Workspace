// 类模板案例
/**
 * 可以对内置数据类型以及自定义数据类型的数据进行存储
 * 将数组中的数据存储到堆区
 * 构造函数中可以传入数组的容量
 * 提供对应的拷贝构造函数以及operator=防止浅拷贝问题
 * 提供尾插法和尾删法对数组中的数据进行增加和删除
 * 可以通过下标的方式访问数组中的元素
 * 可以获取数组中当前元素个数和数组的容量
 */

#pragma once
#include <iostream>
#include <string>
using namespace std;

template <typename T>
class MyArray
{
private:
    T *p_address_; // 地址 (指向数组)
    int capacity_; // 容量 (最大数据量)
    int size_;     // 大小 (实际存放数据量)

public:
    // 构造函数
    MyArray(int arg_capacity)
    {
        cout << "调用构造函数-->";

        this->capacity_ = arg_capacity;
        this->size_ = 0;
        this->p_address_ = new T[this->capacity_];

        cout << "成功! " << endl;
    }

    // 析构函数
    ~MyArray()
    {
        cout << "调用析构函数-->";

        if (this->p_address_ != nullptr)
        {
            delete[] this->p_address_;
            this->p_address_ = nullptr;
        }

        cout << "成功! " << endl;
    }

    // 拷贝构造函数
    MyArray(const MyArray &other)
    {
        cout << "调用拷贝构造函数-->";

        this->capacity_ = other.capacity_;
        this->size_ = other.size_;

        // 深拷贝
        this->p_address_ = new T[other.capacity_];
        for (int i = 0; i < this->size_; i++)
        {
            this->p_address_[i] = other.p_address_[i];
        }

        cout << "成功! " << endl;
    }

    // 重载赋值运算符
    MyArray &operator=(const MyArray &other)
    {
        cout << "重载赋值运算符-->";

        // 判断原先堆区是否有数据, 如果有先释放
        if (this->p_address_ != nullptr)
        {
            delete[] this->p_address_;
            this->p_address_ = nullptr;
        }

        this->capacity_ = other.capacity_;
        this->size_ = other.size_;

        // 深拷贝
        this->p_address_ = new T[this->capacity_];
        for (int i = 0; i < this->size_; i++)
        {
            this->p_address_[i] = other.p_address_[i];
        }

        cout << "成功! " << endl;

        return *this;
    }

    // 重载中括号
    T &operator[](int index)
    {
        return this->p_address_[index];
    }

    // 尾插法
    void pushBack(const T &val)
    {
        cout << "尾插法插入数据-->";

        if (this->capacity_ == this->size_)
        {
            cout << "容量不足, 插入失败! " << endl;

            return;
        }
        else
        {
            this->p_address_[this->size_] = val;
            this->size_++;

            cout << "成功! " << endl;
        }
    }

    // 尾删法
    void popBack()
    {
        cout << "尾删法删除数据-->";

        if (this->size_ == 0)
        {
            cout << "数组为空, 删除失败! " << endl;

            return;
        }
        else
        {
            this->size_--;

            cout << "成功! " << endl;
        }
    }

    // 返回数组容量
    void getCapacity()
    {
        cout << "数组容量为: " << this->capacity_ << endl;
    }

    // 返回数组大小
    void getSize()
    {
        cout << "数组大小为: " << this->size_ << endl;
    }
};
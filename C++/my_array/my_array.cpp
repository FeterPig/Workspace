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

#include "my_array.hpp"

MyArray<int> arr1(5);
MyArray<int> arr2(arr1);

void test1()
{
    arr1.popBack();
    arr1.getCapacity();
    arr1.getSize();
    cout << "第[0]号元素为: " << arr1[0] << endl;
}

void test2()
{
    arr2.pushBack(5);
    arr2.getCapacity();
    arr2.getSize();
    arr2[0] = 1;
    cout << "第[0]号元素为: " << arr2[0] << endl;
}

int main()
{
    arr2 = arr1;
    
    test1();
    test2();

    return 0;
}
// 面向对象的三大特性: 封装、继承、多态

// 封装: 将“数据”（成员变量）和“操作数据的行为”（成员函数）有机地结合在一个类中，并隐藏对象的内部细节，仅对外提供必要的接口。
// 继承: 在一个已存在的类（父类/基类）的基础上建立一个新的类（子类/派生类）。子类会自动拥有父类的成员变量和成员函数，并可以在此基础上添加新功能或修改旧功能。
// 多态: 同一个调用界面（函数名），在不同的对象上表现出不同的行为。

/**
 * 访问权限
 * public: 外部、子类、内部均可访问
 * protected: 外部不能访问, 子类和内部可以访问
 * private: 外部和子类都不能访问, 只有内部可以访问
 */

#include <iostream>
using namespace std;

const double PI = 3.14;

class Circle
{
public:
    int r;

    double func()
    {
        return PI * r * r;
    }
};

int main()
{
    Circle c;
    cout << "请输入圆的半径:";
    cin >> c.r;
    cout << "圆的面积为:" << c.func() << endl;

    return 0;
}
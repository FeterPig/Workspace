// C++11 引入 智能指针 和 右值引用
// C++14 引入 make_unique / make_shared

#include <iostream>
#include <memory>
#include <vector>
using namespace std;

class BigData
{
public:
    BigData() { cout << "执行构造函数\n"; }
    ~BigData() { cout << "执行析构函数\n"; }
};

int main()
{
    auto p1 = make_unique<BigData>(); // 独占智能指针 (一对一 生命周期结束后自动释放内存)
    auto p2 = make_shared<BigData>(); // 共享智能指针 (一对多 多个指针可以指向同一个对象 内置计数器归零后释放内存)

    // 2. 尝试拷贝会报错：p1 是唯一的
    // auto p3 = p1;

    // 3. p2 是共享智能指针 可以拷贝
    auto p3 = p2;

    // 4. 使用右值引用（移动语义）转移所有权
    // move(): 把一个左值（有名字的变量）强制转换成一个右值（临时变量） 不移动内存 节约开支
    auto p4 = move(p1);

    if (p1 == nullptr)
    {
        cout << "p1已置空\n";
        cout << "p4已接管p1资源\n";
    }

    return 0; // 智能指针自动释放
}

#include <iostream>
using namespace std;

template <typename T>
void tmplSwap(T &a, T &b)
{
    T tmp;
    tmp = a;
    a = b;
    b = tmp;
}

// 模板可以重载
void tmplSwap(int &a, int &b)
{
    cout << "不要调用我~" << endl;
}

int main()
{
    int a, b;
    cout << "请输入一组整数: ";
    cin >> a >> b;
    tmplSwap<>(a, b); // 空模板参数, 依然自动推导类型, 但强制使用模板
    cout << "交换后的数据为: " << a << " " << b << endl;

    double c, d;
    cout << "请输入一组浮点数: ";
    cin >> c >> d;
    tmplSwap<>(c, d);
    cout << "交换后的数据为: " << c << " " << d << endl;

    return 0;
}
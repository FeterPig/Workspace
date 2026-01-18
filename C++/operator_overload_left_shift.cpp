// 重载左移运算符

#include <iostream>
using namespace std;

class Cube
{
private:
    int length_;
    int width_;
    int height_;

public:
    Cube(int, int, int);
    friend ostream &operator<<(ostream &os, const Cube &p);
};

Cube::Cube(int length, int width, int height) : length_(length), width_(width), height_(height) {}

ostream &operator<<(ostream &os, const Cube &p)
{
    os << "长方体的信息如下:" << endl
       << "长度: " << p.length_ << endl
       << "宽度: " << p.width_ << endl
       << "高度: " << p.height_;
    return os;
}

int main()
{
    int l, w, h;
    cout << "请输入长方体的(长/宽/高): ";
    cin >> l >> w >> h;

    Cube c(l, w, h);
    cout << c;

    return 0;
}
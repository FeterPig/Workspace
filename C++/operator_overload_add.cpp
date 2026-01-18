// 运算符重载

#include <iostream>
using namespace std;

class Coord
{
private:
    int arg1_, arg2_;

public:
    Coord();
    Coord(int arg1, int arg2);
    ~Coord();

    void showArg(string name) const;
    void showArg(string name, Coord *c1_, Coord *c2_) const;

    Coord operator+(const Coord &other) const;
};

Coord::Coord() {}
Coord::Coord(int arg1, int arg2) : arg1_(arg1), arg2_(arg2) {}
Coord::~Coord() {}

void Coord::showArg(string name) const
{
    cout << name << " = (" << this->arg1_ << "," << this->arg2_ << ")" << endl;
}

void Coord::showArg(string name, Coord *c1_, Coord *c2_) const
{
    cout << name << " = (" << c1_->arg1_ << "," << c1_->arg2_ << ")"
         << " + " << "(" << c2_->arg1_ << "," << c2_->arg2_ << ")"
         << " = (" << this->arg1_ << "," << this->arg2_ << ")" << endl;
}

Coord Coord::operator+(const Coord &other) const
{
    int arg1_new = this->arg1_ + other.arg1_;
    int arg2_new = this->arg2_ + other.arg2_;
    return Coord(arg1_new, arg2_new);
}

int main()
{
    int tmc1, tmc2;

    cout << "请输入c1的参数 (arg1/arg2), 以空格分隔: ";
    cin >> tmc1 >> tmc2;
    Coord c1(tmc1, tmc2);

    cout << "请输入c2的参数 (arg1/arg2), 以空格分隔: ";
    cin >> tmc1 >> tmc2;
    Coord c2(tmc1, tmc2);

    Coord c3 = c1 + c2;
    // Person c3;

    c1.showArg("c1");
    c2.showArg("c2");
    c3.showArg("c3", &c1, &c2);

    return 0;
}
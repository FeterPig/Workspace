#include <iostream>
#include <string>
using namespace std;

class AbstractCalculator
{
protected:
    int num1_, num2_;

public:
    AbstractCalculator(int arg1, int arg2) : num1_(arg1), num2_(arg2) {}

    virtual ~AbstractCalculator() {}

    // 纯虚函数 => 抽象类
    virtual int getResult() = 0;
};

class AddCalculator : public AbstractCalculator
{
public:
    AddCalculator(int a, int b) : AbstractCalculator(a, b) {}

    int getResult() override { return num1_ + num2_; }
};

class SubCalculator : public AbstractCalculator
{
public:
    SubCalculator(int a, int b) : AbstractCalculator(a, b) {}

    int getResult() override { return num1_ - num2_; }
};

void test(int arg1, int arg2)
{
    AbstractCalculator *a = new AddCalculator(arg1, arg2);
    AbstractCalculator *b = new SubCalculator(arg1, arg2);

    cout << "加法结果: " << a->getResult() << endl;
    cout << "减法结果: " << b->getResult() << endl;

    delete a;
    delete b;
}

int main()
{
    test(10, 20);
    return 0;
}
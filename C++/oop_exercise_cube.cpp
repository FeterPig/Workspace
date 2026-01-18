// 设计立方体类, 求出立方体的面积和体积, 判断两个立方体是否相等

#include <iostream>
using namespace std;

class Cube
{
private:
    int length_, width_, height_;
    int area_, volume_;

    int calculateArea() const
    {
        return 2 * (length_ * width_ + length_ * height_ + width_ * height_);
    }
    int calculateVolume() const
    {
        return length_ * width_ * height_;
    }

public:
    Cube(int length, int width, int height);
    //  : length_(length), width_(width), height_(height)
    // {
    //     area_ = calculateArea();
    //     volume_ = calculateVolume();
    // }

    int getArea() const
    {
        return area_;
    }
    int getVolume() const
    {
        return volume_;
    }

    bool isEqual(const Cube &other) const
    {
        return length_ == other.length_ &&
               width_ == other.width_ &&
               height_ == other.height_;
    }
};

// 常用写法: 类内声明, 类外实现
Cube::Cube(int length, int width, int height) : length_(length), width_(width), height_(height)
{
    area_ = calculateArea();
    volume_ = calculateVolume();
}

int main()
{
    int length, width, height;

    cout << "请输入第一个立方体的(长/宽/高), 以空格分隔: ";

    cin >> length >> width >> height;

    Cube cube_1(length, width, height);

    cout << "立方体的表面积为: " << cube_1.getArea() << endl;
    cout << "立方体的体积为: " << cube_1.getVolume() << endl;
    cout << endl;

    cout << "请输入第二个立方体的(长/宽/高), 以空格分隔: ";

    cin >> length >> width >> height;

    Cube cube_2(length, width, height);

    cout << "立方体的表面积为: " << cube_2.getArea() << endl;
    cout << "立方体的体积为: " << cube_2.getVolume() << endl;
    cout << endl;

    if (cube_2.isEqual(cube_1))
    {
        cout << "两个立方体相等 √" << endl;
    }
    else
    {
        cout << "两个立方体不相等 ×" << endl;
    }

    return 0;
}
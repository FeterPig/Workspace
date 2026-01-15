// new关键字 (配合delete关键字使用)

#include <iostream>
using namespace std;

int main()
{
    int *p = new int(10);
    cout << *p << endl;
    delete p;
    // P指向的内存已经被释放, 此时p为野指针
    // cout << *p << endl;

    int *q = new int[10];
    for (int i = 0; i < 10; i++)
    {
        q[i] = i;
        cout << q[i] << ' ';
    }
    delete q;

    return 0;
}
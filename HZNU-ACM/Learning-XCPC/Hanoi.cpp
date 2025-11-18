// 汉诺塔问题
// 借助B柱, 将所有圆盘从 A 柱移动到 C 柱

#include <iostream>
using namespace std;

void hanoi(int n, char from, char to, char aux)
{
    if (n == 0)
    {
        return;
    }

    hanoi(n - 1, from, aux, to);
    cout << from << " -> " << n << " -> " << to << endl;
    hanoi(n - 1, aux, to, from);
}

int main()
{
    int n;
    cin >> n;

    hanoi(n, 'A', 'C', 'B');

    return 0;
}
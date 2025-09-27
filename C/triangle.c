#include <stdio.h>

int main()
{
    int i = 1; // 琛����
    int j = 9; // �����锋��
    int k = 0; // 绌烘�兼��
    int count; // 璁℃�板�����

    while (i <= 5) // 瀹���板��琛�
    {
        for (count = k; count > 0; count--) // 瀹���拌�����绌烘��
        {
            printf(" ");
        }

        for (count = j; count > 0; count--) // 瀹���拌�����������
        {
            printf("*");
        }

        printf("\n");

        k++;
        j -= 2;
        i++;
    }

    return 0;
}
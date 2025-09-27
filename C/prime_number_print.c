// ������100���200涔���寸��绱����

#include <stdio.h>

int isPrime(int num)
{
    int i = 2, j = num - 1, result = -1;

    while (i <= num / 2)
    {
        while (j >= i)
        {
            if (i * j == num)
            {
                result = 0;
                goto end;
            }
            else
                j--;
        }
        i++;
        j = num - 1;
    }
    result = 1;

end:
    return result;
}

void print_prime(int num)
{
    printf("%d\n", num);
}

int main()
{
    int num = 100;

    while (num <= 200)
    {
        int is = isPrime(num);

        switch (is)
        {
        case 1:
            print_prime(num);
            break;

        default:
            break;
        }
        num++;
    }

    return 0;
}
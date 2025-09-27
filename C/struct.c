#include <stdio.h>
#include <string.h>

struct Person
{
    char name[20];
    char sex[5];
    char tel[12];
    int age;
    int height;
    int weight;
};

int main()
{
    struct Person p1 = {"彭相博", "男", "19553233055", 18, 188, 125};

    printf("%s\n%s\n%s\n%d\n%d\n%d\n", p1.name, p1.sex, p1.tel, p1.age, p1.height, p1.weight);

    // struct Person *p_p1 = &p1;
    // printf("%d", p_p1->age);

    return 0;
}
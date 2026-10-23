#include <stdio.h>
#include <string.h>

struct dob
{
    int day, month, year;
};

struct student_info
{
    int roll;
    char name[30];
    float cgpa;
    struct dob age;
};

void value(struct student_info s)
{
    printf("\nPass by Value\n");
    printf("%d %s %.2f %d/%d/%d\n",s.roll, s.name, s.cgpa,s.age.day, s.age.month, s.age.year);
}

void address(struct student_info *s)
{
    printf("\nPass by Address\n");
    printf("%d %s %.2f %d/%d/%d\n",s->roll, s->name, s->cgpa,s->age.day, s->age.month, s->age.year);
}

int main()
{
    struct student_info s;

    s.roll = 10;
    strcpy(s.name, "Rahul");
    s.cgpa = 8.9;

    s.age.day = 20;
    s.age.month = 5;
    s.age.year = 2004;

    value(s);
    address(&s);

    return 0;
}

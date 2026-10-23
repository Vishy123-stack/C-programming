#include <stdio.h>

struct pkt
{
    char ch1;
    char ch2[2];
    char ch3;
};

int main()
{
    unsigned int num, result;
    struct pkt p;

    printf("Enter a number: ");
    scanf("%u", &num);

    char *ptr = (char *)&num;

    p.ch1 = ptr[0];
    p.ch2[0] = ptr[1];
    p.ch2[1] = ptr[2];
    p.ch3 = ptr[3];


    printf("\nContents of structure:\n");
    printf("ch1    = %u\n", (unsigned char)p.ch1);
    printf("ch2[0] = %u\n", (unsigned char)p.ch2[0]);
    printf("ch2[1] = %u\n", (unsigned char)p.ch2[1]);
    printf("ch3    = %u\n", (unsigned char)p.ch3);


    char *res = (char *)&result;

    res[0] = p.ch1;
    res[1] = p.ch2[0];
    res[2] = p.ch2[1];
    res[3] = p.ch3;

    printf("\nReconstructed Number = %u\n", result);

    return 0;
}
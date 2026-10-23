#include <stdio.h>

int main()
{
    unsigned int num;
    unsigned char b1, b2, b3, b4;

    printf("Enter a 32-bit integer: ");
    scanf("%u", &num);

    b1 = num & 0xFF;
    b2 = (num >> 8) & 0xFF;
    b3 = (num >> 16) & 0xFF;
    b4 = (num >> 24) & 0xFF;

    printf("\nExtracted Bytes:\n");
    printf("Byte 1 = %u\n", b1);
    printf("Byte 2 = %u\n", b2);
    printf("Byte 3 = %u\n", b3);
    printf("Byte 4 = %u\n", b4);

    return 0;
}
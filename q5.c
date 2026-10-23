#include <stdio.h>
unsigned int swapEndian(unsigned int num)
{
    return ((num >> 24) & 0x000000FF) |
           ((num >> 8)  & 0x0000FF00) |
           ((num << 8)  & 0x00FF0000) |
           ((num << 24) & 0xFF000000);
}
int main()
{
    unsigned int x = 0x12345678;
    char *c = (char *)&x;

    printf("Original Number : 0x%X\n", x);

    if (*c == 0x78)
        printf("System is Little Endian\n");
    else
        printf("System is Big Endian\n");

    printf("\nBytes:\n");
    for (int i = 0; i < 4; i++)
    {
        printf("Byte %d = 0x%X\n", i + 1, (unsigned char)c[i]);
    }

    unsigned int swapped = swapEndian(x);

    printf("\nConverted (Swapped) Endian : 0x%X\n", swapped);

    return 0;
}
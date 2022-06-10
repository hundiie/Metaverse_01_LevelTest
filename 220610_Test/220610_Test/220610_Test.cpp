#include <iostream>
#include "220610_Test.h"

void swap1(int* a, int* b)
{
    int c = *a;
    *a = *b;
    *b = c;
}
void swap2(int& a, int& b)
{
    int c = a;
    a = b;
    b = c;
}
int main(void)
{
    int a = 10;
    int b = 20;
    
    swap1(&a, &b);

    printf("%d\n", a);
    printf("%d\n", b);
    
    swap2(a, b);

    printf("%d\n",a);
    printf("%d\n",b);

    return 0;
}

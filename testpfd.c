#include <stdio.h>

int main(void) {
        int a = 10;
        int *b = &a;
        printf("%p\n",b);
        printf("%X\n",b);
}
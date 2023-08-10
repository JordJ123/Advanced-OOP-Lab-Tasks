#include <stdio.h>
#include <stdlib.h>
#include "fibonacci.h"

int main(int argc, char* argv[]) {
    int num = atoi(argv[1]);
    int result = fibonacci(num);
    printf("Fibonacci of %d = %d\n", num, result);
    return 0;
}
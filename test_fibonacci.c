#include <stdio.h>
#include <assert.h>
#include "fibonacci.c"  // Include the source code file with Fibonacci calculation

void testFibonacci() {
    assert(fibonacci(0) == 0);
    assert(fibonacci(1) == 1);

    assert(fibonacci(5) == 5);
    assert(fibonacci(10) == 55);

}

int main() {
    testFibonacci();

    printf("All tests passed successfully!\n");

    return 0;
}

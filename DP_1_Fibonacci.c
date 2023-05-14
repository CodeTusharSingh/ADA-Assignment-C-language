#include <stdio.h>

#define MAX_SIZE 100

int fib[MAX_SIZE];

int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }

    if (fib[n] != -1) {
        return fib[n];
    }

    fib[n] = fibonacci(n - 1) + fibonacci(n - 2);
    return fib[n];
}

int main() {
    int n, i;
    printf("Enter the value of n: ");
    scanf("%d", &n);
  
    for (i = 0; i < MAX_SIZE; i++) {
        fib[i] = -1;
    }

    int result = fibonacci(n);
    printf("The %dth Fibonacci number is: %d\n", n, result);

    return 0;
}

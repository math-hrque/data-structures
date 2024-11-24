#include <stdio.h>

int fibonacciRecursive(int n) {
    if (n <= 1) return n;
    return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}

int fibonacciIterative(int n) {
    if (n <= 1) return n;
    int a = 0, b = 1, c;
    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int main() {
    int n;

    printf("Enter the position for Fibonacci sequence: ");
    scanf("%d", &n);

    printf("\nRecursive Fibonacci (%d): %d\n", n, fibonacciRecursive(n));
    printf("Iterative Fibonacci (%d): %d\n", n, fibonacciIterative(n));

    return 0;
}

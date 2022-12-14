#include <stdio.h>

int fibonacci_recursive(int n) {
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);
    }
}

int fibonacci_iteration(int n) {
    int a = 0;
    int b = 1;
    int c = 0;
    for (int i = 0; i < n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return a;
}

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    int result_1 = fibonacci_recursive(n);
    printf("The %dth Fibonacci number is %d\n", n, result_1);

    int result_2 = fibonacci_iteration(n);
    printf("The %dth Fibonacci number is %d\n", n, result_2);

    return 0;
}
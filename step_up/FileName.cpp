#include <stdio.h>
int factorial(int n);
int main() {
    int n;
    scanf_s("%d", &n);
    factorial(n);
    printf("%d", factorial(n));
    return 0;
}
int factorial(int n) {
    if (n == 1) {
        return 1;
    }
    else {
        return n * factorial(n - 1);
    }
}
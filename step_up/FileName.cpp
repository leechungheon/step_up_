#include <stdio.h>
int main() {
    char text;

    scanf_s("%c", &text);
    printf("%d\n", text);
    printf("%c\n", text);
    printf("%.2f\n", text);

    return 0;
}
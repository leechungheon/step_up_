#include <stdio.h>
int sum(int array[][5]) {
    int total = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            total += array[i][j];
        }
    }
    return total;
}
void main() {
    int array[5][5];
    int num;
    scanf_s("%d", &num);
    for (int i = 0; i <= num; i++) {
        for (int j = 0; j <= num; j++) {
            array[i][j] = num;
        }
    }
    printf("%d", sum(array));
}
#include <stdio.h>
void bubbleSort(int array[], int n) {
    int token = 0;
    do{
        token = 0;
        for (int i = 0; i + 1 < n; i++) {
            if (array[i] > array[i + 1]) {
                int num = array[i];
                array[i] = array[i + 1];
                array[i + 1] = num;
                token++;
            }
        }
    } while (token != 0);
}
int main() {

    int arr[] = { 64, 34, 25, 12, 22, 11, 90 };

    int n = sizeof(arr) / sizeof(arr[0]);

    // 버블 정렬 수행

    bubbleSort(arr, n);

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;

}
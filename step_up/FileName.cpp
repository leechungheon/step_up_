#include <stdio.h>
int deleteElement(int arr[], int* size, int value) {
    for (int i = 0; i < *size; i++) {
        if (arr[i] == value) {
            int num = i;
            for (; i+1 < *size; i++) {
                arr[i] = arr[i + 1];
            }
            *size = 4;
            return 1;
        }
    }
    return 0;
}
int main() {

    int arr[] = { 1, 2, 3, 4, 5 };

    int size = 5; // �迭�� �ʱ� ũ��

    int value, found;



    scanf_s("%d", &value); //������ �� �Է�



    found = deleteElement(arr, &size, value);


    if (found) {

        for (int i = 0; i < size; i++) {

            printf("%d ", arr[i]);

        }

    }

    else

        printf("Not found");



    return 0;

}
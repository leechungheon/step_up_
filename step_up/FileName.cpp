
#include<stdio.h>
#define SIZE 100
int stack[SIZE], choice, top;
void push(int x) {
    stack[++top] = x;
    choice = top;
}
int pop(void) {
    int num = stack[top];
    stack[top--] = 0;
    choice--;
    return num;
}
void display(void) {
    int i;
    if (top >= 0) {
        for (i = top; i >= 0; i--)
            printf("%d ", stack[i]);
    }
    else {
        printf("\n STACK Empty");
    }
}
int main() {
    int i;
    top = -1;
    int num;

    for (i = 1; i <= 3; i++) {
        scanf_s("%d", &num);
        push(num);
    }
    pop();
    display();
    return 0;
}
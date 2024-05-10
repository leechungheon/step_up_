#include<stdio.h>

#define SIZE 100

int stack[SIZE], choice, top;

void push(int x);

int pop(void);

void display(void);

int main()

{

    top = -1;



    push(1);

    push(2);

    push(3);

    push(4);

    push(5);

    display();



    pop();

    pop();

    display();



    return 0;

}

void push(int x)

{
    stack[++top]=x;
    choice = top;
}

int pop()

{
    int num;
    num = stack[top];
    stack[top--] = 0;
    choice = top;
    return num;
}

void display()

{
    for (int i = choice; i >= 0; i--) {
        printf("%d\n", stack[i]);
    }
}
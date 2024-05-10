#include <stdio.h>

#include <stdlib.h>



void push(int);

int pop();

void print_s();



typedef struct node {

    int data;

    struct node* next;

}stack;





stack* top = NULL;



int main() {

    push(1);

    push(2);

    push(3);

    push(4);

    push(5);

    print_s();



    pop();

    pop();

    print_s();

}



void push(int data) {
    stack *newNode = (stack*)malloc(sizeof(stack));
    //struct node* newNode; 기존 오류 코드 수정
    if (newNode == NULL) {
        printf("Overstack!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = top;
    top = newNode;
}

                                                                                                                           
int pop() {
    stack* del;
    int value;

    if (top == NULL) {
        printf("stack is empty!");
        exit(1);
    }
    value = top->data;
    del = top;
    top = top->next;
    free(del);

    return value;
}
                                                                                                                             
void print_s() {
    stack* i;
    stack* count = top;

    i = count;
    while (i != NULL) {

        printf("%d \n", i->data);
        i = count->next;
        count = count->next;

    }

    printf("\n");
}


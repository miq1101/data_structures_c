#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_INT 2147483646
#define MIN_INT -2147483647


typedef struct node {
    int value;
    struct node *next;
} node_s;


typedef struct stack {
    node_s *top;
} stack_n;


stack_n* createStack() {
    stack_n *stack = (stack_n*)malloc(sizeof(stack_n));
    stack->top = NULL;
    return stack;
}


node_s* createNewNode(int value) {
    node_s* newNode = (node_s*)malloc(sizeof(node_s));
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}


bool isEmptyStack(stack_n *stack) {
    if (stack->top == NULL) {
        return true;
    }

    return false;
}


void printStack(stack_n *stack) {
    if (isEmptyStack(stack)) {
        printf("Stack is empty\n");
        return;
    }

    node_s *temp = stack->top;
    while (temp != NULL) {
        printf("%d ", temp->value);
        temp = temp->next;
    }

    printf("\n");
}


void push(stack_n* stack, int value) {
    if (value < MIN_INT || value > MAX_INT) {
        printf("Please select number from %d to %d.\n", MIN_INT, MAX_INT);
        return;
    }

    node_s* new_node = createNewNode(value);
    if (isEmptyStack(stack)) {
        stack->top = new_node;
        return;
    }

    new_node->next = stack->top;
    stack->top = new_node;
}

void pop(stack_n **stack) {
    if (isEmptyStack(*stack)) {
        printf("Stack is empty\n");
        return;
    }

    node_s *temp = (*stack)->top->next;
    free((*stack)->top);
    (*stack)->top = temp;
}


int top(stack_n *stack) {
    if (isEmptyStack(stack)) {
        printf("Stack is empty\n");
        return MIN_INT;
    }

    return stack->top->value;
}



void clear(stack_n **stack) {
    if (isEmptyStack(*stack)) {
        printf("Stack is already empty\n");
        return;
    }

    while((*stack)->top != NULL) {
        pop(stack);
    }
}


int main() {
    stack_n* stack = createStack();
    printStack(stack);
    push(stack, 1);
    printStack(stack);
    push(stack, 2);
    printStack(stack);
    pop(&stack);
    printStack(stack);
    pop(&stack);
    printStack(stack);
    push(stack, 3);
    printStack(stack);
    push(stack, 4);
    printStack(stack);
    push(stack, 5);


    printStack(stack);
    printf("Stack Front : %d \n", stack->top->value);


    clear(&stack);
    free(stack);
}

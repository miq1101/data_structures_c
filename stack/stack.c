#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_INT 2147483646
#define MIN_INT -2147483647
#define MIN_ELEMENT_SIZE 20


typedef struct stack {
    int items[MIN_ELEMENT_SIZE];
    int top;
} stack_n;


void createStack(stack_n *stack) {
    stack->top = -1;
}


bool isFull(stack_n *stack) {
    if (stack->top == MIN_ELEMENT_SIZE - 1) {
        printf("Stack is full\n");
        return true;
    }

    return false;
}


bool isEmpty(stack_n *stack) {
    if (stack->top == -1) {
        printf("Stack is empty \n");
        return true;
    }

    return false;
}


int top(stack_n *stack) {
    if (isEmpty(stack)) {
        return MIN_INT;
    }

    return stack->items[stack->top];
}


void push(stack_n *stack, int value) {
    if (value < MIN_INT || value > MAX_INT) {
        printf("Please select number from %d to %d.\n", MIN_INT, MAX_INT);
        return;
    }

    if (isFull(stack)) {
        return;
    }

    stack->top++;
    stack->items[stack->top] = value;
}


void pop(stack_n *stack) {
    if (isEmpty(stack)) {
        return;
    }

    stack->top--;
}


void clear(stack_n *stack) {
    if (isEmpty(stack)) {
        return;
    }

    stack->top = -1;
}


void printStack(stack_n *stack) {
    int actual_size = stack->top;
    if (isEmpty(stack)) {
        return;
    }

    for (int i = 0; i <= actual_size; i++) {
        printf("%d ", stack->items[i]);
    }

    printf("\n");
}


int main() {
  stack_n *stack = (stack_n *)malloc(sizeof(stack_n));

  createStack(stack);

  push(stack, 1);
  push(stack, 2);
  push(stack, 3);
  push(stack, 4);

  printStack(stack);
  pop(stack);
  push(stack, 5);
  printStack(stack);
  clear(stack);
  printStack(stack);


  free(stack);
}
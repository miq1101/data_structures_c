#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_INT 2147483646
#define MIN_INT -2147483647


typedef struct node {
    int value;
    struct node *next;
} node_q;


typedef struct queue {
    node_q *front;
    node_q *end;
} queue_n;


queue_n *createQueue() {
    queue_n *queue = (queue_n*)malloc(sizeof(queue_n));
    queue->end = NULL;
    queue->front = queue->end;
    return queue;
}


node_q *createNewNode(int value) {
    node_q *newNode = (node_q*)malloc(sizeof(node_q));
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}


bool isEmptyQueue(queue_n *queue) {
    if (queue->end == NULL) {
        return true;
    }

    return false;
}


void printQueue(queue_n *queue) {
    if (isEmptyQueue(queue)) {
        printf("Queue is empty\n");
        return;
    }

    node_q *temp = queue->front;
    while (temp != NULL) {
        printf("%d ", temp->value);
        temp = temp->next;
    }

    printf("\n");
}


void push(queue_n *queue, int value) {
    if (value < MIN_INT || value > MAX_INT) {
        printf("Please select number from %d to %d.\n", MIN_INT, MAX_INT);
        return;
    }

    node_q *new_node = createNewNode(value);
    if (isEmptyQueue(queue)) {
        queue->front = new_node;
        queue->end = queue->front;
        return;
    }

    queue->end->next = new_node;
    queue->end = new_node;
}

void pop(queue_n **queue) {
    if (isEmptyQueue(*queue)) {
        printf("Queue is empty\n");
        return;
    }

    node_q *temp = (*queue)->front;
    (*queue)->front = (*queue)->front->next;
    if ((*queue)->front == NULL) {
        (*queue)->end = NULL;
    }

    free(temp);
}


int front(queue_n *queue) {
    if (isEmptyQueue(queue)) {
        printf("Queue is empty\n");
        return MIN_INT;
    }

    return queue->front->value;
}


int end(queue_n *queue) {
    if (isEmptyQueue(queue)) {
        printf("Queue is empty\n");
        return MIN_INT;
    }

    return queue->end->value;
}


void clear(queue_n **queue) {
    if (isEmptyQueue(*queue)) {
        printf("Queue is already empty\n");
        return;
    }

    while((*queue)->front != NULL) {
        pop(queue);
    }
}


int main() {
    queue_n *queue = createQueue();
    printQueue(queue);
    push(queue, 1);
    printQueue(queue);
    push(queue, 2);
    printQueue(queue);
    pop(&queue);
    printQueue(queue);
    pop(&queue);
    printQueue(queue);
    push(queue, 3);
    printQueue(queue);
    push(queue, 4);
    printQueue(queue);
    push(queue, 5);


    printQueue(queue);
    printf("Queue Front : %d \n", queue->front->value);
    printf("Queue End : %d\n", queue->end->value);

    clear(&queue);
    free(queue);
}
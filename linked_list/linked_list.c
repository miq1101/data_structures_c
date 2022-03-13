#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_INT 2147483646
#define MIN_INT -2147483647

typedef struct node {
    int value;
    struct node *next;
} node_ll;


node_ll* createNewNode(int value) {
    node_ll *newNode = (node_ll*)malloc(sizeof(node_ll));
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}


bool isEmpty (node_ll *root) {
    if (root == NULL) {
        printf("List is empty\n");
        return true;
    }

    return false;
}


void printList(node_ll *root) {
    node_ll *temp = root;
    if (isEmpty(root)) {
        return;
    }

    while (temp != NULL) {
        printf("%d ", temp->value);
        temp = temp->next;
    }

    printf("\n");
}


void push(node_ll **root, int value) {
    if (value < MIN_INT || value > MAX_INT) {
        printf("Please select number from %d to %d.\n", MIN_INT, MAX_INT);
        return;
    }

    node_ll* new_node = createNewNode(value);
    new_node->next = (*root);
    (*root) = new_node;
}


void pop(node_ll **root) {
    if (isEmpty(*root)) {
        return;
    }

    node_ll *next_node = (*root)->next;
    free(*root);
    *root = next_node;
}


void removeList(node_ll **root) {
    if (isEmpty(*root)) {
        return;
    }

    while (*root != NULL) {
        pop(root);
    }
}


void removeByValue(node_ll **root, int value) {
    if (value < MIN_INT || value > MAX_INT) {
        printf("Please select number from %d to %d.\n", MIN_INT, MAX_INT);
        return;
    }

    if ((*root)->value == value) {
        pop(root);
        return;
    } else if ((*root)->value != value && (*root)->next == NULL) {
        printf("%d not found in the list.\n", value);
    }

    node_ll *current = *root;
    node_ll *prev = NULL;

    while (current->next != NULL && current->value != value) {
        prev = current;
        current = current->next;
    }

    if(current->value == value) {
        if (current->next != NULL) {
            prev->next = current->next;
        }

        free(current);
    } else {
        printf("%d not found in the list.\n", value);
    }
}


int main() {
    node_ll *root = createNewNode(1);

    push(&root, 3);
    push(&root, 21474836);
    push(&root, 5);
    push(&root, 5);
    push(&root, 4);
    push(&root, 5);
    push(&root, 7);
    printList(root);
    removeByValue(&root, 5);
    printList(root);
    printList(root);



    removeList(&root);
}

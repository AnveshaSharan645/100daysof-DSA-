/*
Problem: Doubly Linked List Insertion and Traversal - 
Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the linked list elements in forward order, space-separated

Example:
Input:
5
10 20 30 40 50

Output:
10 20 30 40 50

Explanation:
Each node has data, next, prev. Insert nodes sequentially, 
traverse from head using next pointer.
*/

#include <stdio.h>
#include <stdlib.h>

// Structure of Doubly Linked List Node
struct node {
    int data;
    struct node* next;
    struct node* prev;
};

// Function to create doubly linked list
struct node* createList(int n) {
    struct node *head = NULL, *temp = NULL, *newNode = NULL;

    for (int i = 0; i < n; i++) {
        newNode = (struct node*)malloc(sizeof(struct node));
        scanf("%d", &newNode->data);

        newNode->next = NULL;
        newNode->prev = NULL;

        if (head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            newNode->prev = temp;
            temp = newNode;
        }
    }

    return head;
}

// Function to traverse and print list in forward direction
void traverseForward(struct node* head) {
    struct node* temp = head;

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    struct node* head = createList(n);

    traverseForward(head);

    return 0;
}
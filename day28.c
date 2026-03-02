/*

Problem: Circular Linked List Creation and Traversal - 
Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the circular linked list elements starting from head, space-separated

Example:
Input:
5
10 20 30 40 50

Output:
10 20 30 40 50

Explanation:
Last node's next points to head. 
Traverse from head until returning to head to avoid infinite loop.
*/

#include <stdio.h>
#include <stdlib.h>

// Structure of node
struct node {
    int data;
    struct node* next;
};

// Function to create circular linked list
struct node* createCircularList(int n) {
    struct node *head = NULL, *temp = NULL, *newNode = NULL;

    for (int i = 0; i < n; i++) {
        newNode = (struct node*)malloc(sizeof(struct node));
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    // Make last node point to head (circular)
    if (temp != NULL) {
        temp->next = head;
    }

    return head;
}

// Function to traverse circular list
void traverseCircular(struct node* head) {
    if (head == NULL)
        return;

    struct node* temp = head;

    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);   // Stop when back to head
}

int main() {
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    struct node* head = createCircularList(n);

    traverseCircular(head);

    return 0;
}
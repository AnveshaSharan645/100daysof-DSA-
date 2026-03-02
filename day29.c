/*

Problem: Rotate Linked List Right by k Places - 
Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers
- Third line: integer k

Output:
- Print the linked list elements after rotation, space-separated

Example:
Input:
5
10 20 30 40 50
2

Output:
40 50 10 20 30

Explanation:
Connect last node to head forming circular list. 
Traverse to (n-k)th node, set next to NULL, 
update head to (n-k+1)th node.
*/

#include <stdio.h>
#include <stdlib.h>

// Structure of node
struct node {
    int data;
    struct node* next;
};

// Function to create linked list
struct node* createList(int n) {
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
    return head;
}

// Function to rotate list right by k places
struct node* rotateRight(struct node* head, int k) {
    if (head == NULL || head->next == NULL || k == 0)
        return head;

    struct node* temp = head;
    int length = 1;

    // Find length and last node
    while (temp->next != NULL) {
        temp = temp->next;
        length++;
    }

    // Make it circular
    temp->next = head;

    k = k % length;  // Handle k > length
    int steps = length - k;

    // Traverse to (length-k)th node
    struct node* newTail = head;
    for (int i = 1; i < steps; i++) {
        newTail = newTail->next;
    }

    // New head
    struct node* newHead = newTail->next;

    // Break circular link
    newTail->next = NULL;

    return newHead;
}

// Function to print list
void printList(struct node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    int n, k;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    struct node* head = createList(n);
    printf("Enter k: ");
    scanf("%d", &k);

    head = rotateRight(head, k);

    printList(head);

    return 0;
}
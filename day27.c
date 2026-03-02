/*


Problem: Find Intersection Point of Two Linked Lists - 
Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers (first list)
- Third line: integer m
- Fourth line: m space-separated integers (second list)

Output:
- Print value of intersection node or 'No Intersection'

Example:
Input:
5
10 20 30 40 50
4
15 25 30 40 50

Output:
30

Explanation:
Calculate lengths, advance pointer in longer list, traverse both simultaneously. 
First common node is intersection.
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

// Function to get length of list
int getLength(struct node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

// Function to find intersection
int findIntersection(struct node* head1, struct node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    int diff = abs(len1 - len2);

    // Move pointer of longer list ahead
    if (len1 > len2) {
        for (int i = 0; i < diff; i++)
            head1 = head1->next;
    } else {
        for (int i = 0; i < diff; i++)
            head2 = head2->next;
    }

    // Traverse both lists together
    while (head1 != NULL && head2 != NULL) {
        if (head1->data == head2->data) {
            return head1->data;  // Intersection found
        }
        head1 = head1->next;
        head2 = head2->next;
    }

    return -1;  // No intersection
}

int main() {
    int n, m;
    printf("Enter number of nodes in first list: ");
    scanf("%d", &n);
    struct node* head1 = createList(n);
    printf("Enter number of nodes in second list: ");
    scanf("%d", &m);
    struct node* head2 = createList(m);

    int result = findIntersection(head1, head2);

    if (result == -1)
        printf("No Intersection");
    else
        printf("%d", result);

    return 0;
}
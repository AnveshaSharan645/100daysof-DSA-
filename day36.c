/*
Problem: Circular Queue Using Array

Input:
- First line: integer n (number of elements to enqueue)
- Second line: n space-separated integers
- Third line: integer m (number of dequeue operations)

Output:
- Print queue elements from front to rear after operations, space-separated

Example:
Input:
5
10 20 30 40 50
2

Output:
30 40 50 10 20
*/

#include <stdio.h>

#define MAX 100

int queue[MAX];
int front = -1, rear = -1;
int size;

/* Enqueue operation */
void enqueue(int value)
{
    if ((rear + 1) % size == front)
    {
        printf("Queue Overflow\n");
        return;
    }

    if (front == -1)
        front = 0;

    rear = (rear + 1) % size;
    queue[rear] = value;
}

/* Dequeue operation */
void dequeue()
{
    if (front == -1)
    {
        printf("Queue Underflow\n");
        return;
    }

    if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front = (front + 1) % size;
    }
}

/* Display queue */
void display()
{
    if (front == -1)
        return;

    int i = front;

    while (1)
    {
        printf("%d ", queue[i]);

        if (i == rear)
            break;

        i = (i + 1) % size;
    }
}

int main()
{
    int n, m, i, x;

    scanf("%d", &n);
    size = n;

    for (i = 0; i < n; i++)
    {
        scanf("%d", &x);
        enqueue(x);
    }

    scanf("%d", &m);

    for (i = 0; i < m; i++)
        dequeue();

    display();

    return 0;
}
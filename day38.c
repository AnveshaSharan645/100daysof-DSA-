// Problem: Deque (Double-Ended Queue)

// A Deque is a linear data structure that allows insertion and deletion of elements from both the front and the rear. It provides more flexibility than a standard queue or stack.

// Common Operations:
// 1. push_front(value): Insert an element at the front of the deque.
// 2. push_back(value): Insert an element at the rear of the deque.
// 3. pop_front(): Remove an element from the front of the deque.
// 4. pop_back(): Remove an element from the rear of the deque.
// 5. front(): Return the front element of the deque.
// 6. back(): Return the rear element of the deque.
// 7. empty(): Check whether the deque is empty.
// 8. size(): Return the number of elements in the deque.

// Additional Operations:
// - clear(): Remove all elements from the deque.
// - erase(): Remove one or more elements from the deque.
// - swap(): Swap contents of two deques.
// - emplace_front(): Insert an element at the front without copying.
// - emplace_back(): Insert an element at the rear without copying.
// - resize(): Change the size of the deque.
// - assign(): Replace elements with new values.
// - reverse(): Reverse the order of elements.
// - sort(): Sort the elements in ascending order.

// Time Complexity:
// - push_front, push_back, pop_front, pop_back, front, back, empty, size: O(1)
// - clear, erase, resize, assign, reverse: O(n)
// - sort: O(n log n)

// Input:
// - Sequence of deque operations with values (if applicable)

// Output:

#include <stdio.h>

#define MAX 100

int deque[MAX];
int front = -1;
int rear = -1;

int empty() {
    if(front == -1)
        return 1;
    return 0;
}

int size() {
    if(front == -1)
        return 0;
    return rear - front + 1;
}

void push_front(int x) {
    if(front == 0) {
        printf("Overflow\n");
        return;
    }

    if(front == -1) {
        front = rear = 0;
    }
    else {
        front--;
    }

    deque[front] = x;
}

void push_back(int x) {
    if(rear == MAX - 1) {
        printf("Overflow\n");
        return;
    }

    if(front == -1) {
        front = rear = 0;
    }
    else {
        rear++;
    }

    deque[rear] = x;
}

void pop_front() {
    if(empty()) {
        printf("Underflow\n");
        return;
    }

    printf("%d\n", deque[front]);

    if(front == rear) {
        front = rear = -1;
    }
    else {
        front++;
    }
}

void pop_back() {
    if(empty()) {
        printf("Underflow\n");
        return;
    }

    printf("%d\n", deque[rear]);

    if(front == rear) {
        front = rear = -1;
    }
    else {
        rear--;
    }
}

void display() {
    if(empty()) {
        printf("Deque Empty\n");
        return;
    }

    for(int i = front; i <= rear; i++) {
        printf("%d ", deque[i]);
    }
    printf("\n");
}

void clear() {
    front = rear = -1;
}

void reverse() {
    int i = front;
    int j = rear;

    while(i < j) {
        int temp = deque[i];
        deque[i] = deque[j];
        deque[j] = temp;
        i++;
        j--;
    }
}

void sort() {
    for(int i = front; i <= rear; i++) {
        for(int j = i + 1; j <= rear; j++) {
            if(deque[i] > deque[j]) {
                int temp = deque[i];
                deque[i] = deque[j];
                deque[j] = temp;
            }
        }
    }
}

int front_element() {
    if(empty())
        return -1;
    return deque[front];
}

int back_element() {
    if(empty())
        return -1;
    return deque[rear];
}

int main() {

    push_back(10);
    push_back(20);
    push_front(5);
    push_back(30);

    display();

    pop_front();
    pop_back();

    display();

    reverse();
    display();

    sort();
    display();

    printf("Front: %d\n", front_element());
    printf("Back: %d\n", back_element());
    printf("Size: %d\n", size());

    clear();
    printf("Empty: %d\n", empty());

    return 0;
}
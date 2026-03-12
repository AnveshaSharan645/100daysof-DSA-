#include <stdio.h>
#include <string.h>

int heap[1000];
int size = 0;

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void insert(int x)
{
    heap[size] = x;
    int i = size;
    size++;

    while(i > 0 && heap[(i-1)/2] > heap[i])
    {
        swap(&heap[i], &heap[(i-1)/2]);
        i = (i-1)/2;
    }
}

int extractmin()
{
    if(size == 0)
        return -1;

    int min = heap[0];
    heap[0] = heap[size-1];
    size--;

    int i = 0;

    while(1)
    {
        int left = 2*i + 1;
        int right = 2*i + 2;
        int smallest = i;

        if(left < size && heap[left] < heap[smallest])
            smallest = left;

        if(right < size && heap[right] < heap[smallest])
            smallest = right;

        if(smallest != i)
        {
            swap(&heap[i], &heap[smallest]);
            i = smallest;
        }
        else
            break;
    }

    return min;
}

int peek()
{
    if(size == 0)
        return -1;
    return heap[0];
}

int main()
{
    int n;

    printf("enter number of operations: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        char op[20];

        printf("enter operation: ");
        scanf("%s", op);

        if(strcmp(op,"insert") == 0)
        {
            int x;
            scanf("%d",&x);
            insert(x);
        }
        else if(strcmp(op,"extractMin") == 0)
        {
            printf("%d\n", extractmin());
        }
        else if(strcmp(op,"peek") == 0)
        {
            printf("%d\n", peek());
        }
    }

    return 0;
}
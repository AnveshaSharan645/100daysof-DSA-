#include <stdio.h>

int main()
{
    int r, c;
    scanf("%d %d", &r, &c);

    int a[100][100];

    // input matrix
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            scanf("%d", &a[i][j]);

    int top = 0;
    int bottom = r - 1;
    int left = 0;
    int right = c - 1;

    while(top <= bottom && left <= right)
    {
        // 1️⃣ Left → Right (top row)
        for(int j = left; j <= right; j++)
            printf("%d ", a[top][j]);
        top++;

        // 2️⃣ Top → Bottom (right column)
        for(int i = top; i <= bottom; i++)
            printf("%d ", a[i][right]);
        right--;

        // 3️⃣ Right → Left (bottom row)
        if(top <= bottom)
        {
            for(int j = right; j >= left; j--)
                printf("%d ", a[bottom][j]);
            bottom--;
        }

        // 4️⃣ Bottom → Top (left column)
        if(left <= right)
        {
            for(int i = bottom; i >= top; i--)
                printf("%d ", a[i][left]);
            left++;
        }
    }

    return 0;
}
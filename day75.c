#include <stdio.h>

int maxLenZeroSum(int arr[], int n) {
    int sum = 0, maxLen = 0;

    // Array to store prefix sums (for simplicity)
    int prefix[1000];

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        // If sum becomes 0 → subarray from 0 to i
        if (sum == 0) {
            maxLen = i + 1;
        }

        // Check if same sum appeared before
        for (int j = 0; j < i; j++) {
            if (prefix[j] == sum) {
                if (maxLen < i - j) {
                    maxLen = i - j;
                }
            }
        }

        prefix[i] = sum;
    }

    return maxLen;
}

int main() {
    int arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("%d", maxLenZeroSum(arr, n));

    return 0;
}
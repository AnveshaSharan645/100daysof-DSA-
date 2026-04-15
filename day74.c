#include <stdio.h>
#include <string.h>

#define MAX 1000
#define LEN 50

int main() {
    int n;
    scanf("%d", &n);

    char names[MAX][LEN];     // input names
    char unique[MAX][LEN];    // unique candidates
    int count[MAX] = {0};     // vote count

    for (int i = 0; i < n; i++) {
        scanf("%s", names[i]);
    }

    int uniqueSize = 0;

    // Count frequency
    for (int i = 0; i < n; i++) {
        int found = -1;

        for (int j = 0; j < uniqueSize; j++) {
            if (strcmp(names[i], unique[j]) == 0) {
                found = j;
                break;
            }
        }

        if (found != -1) {
            count[found]++;
        } else {
            strcpy(unique[uniqueSize], names[i]);
            count[uniqueSize] = 1;
            uniqueSize++;
        }
    }

    // Find winner
    int maxVotes = -1;
    char winner[LEN];

    for (int i = 0; i < uniqueSize; i++) {
        if (count[i] > maxVotes) {
            maxVotes = count[i];
            strcpy(winner, unique[i]);
        } 
        else if (count[i] == maxVotes) {
            if (strcmp(unique[i], winner) < 0) {
                strcpy(winner, unique[i]);
            }
        }
    }

    printf("%s %d\n", winner, maxVotes);

    return 0;
}
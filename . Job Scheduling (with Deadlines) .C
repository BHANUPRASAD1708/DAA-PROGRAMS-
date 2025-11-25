#include <stdio.h>
#include <stdbool.h>

typedef struct {
    char id;
    int deadline;
    int profit;
} Job;

void jobSequencing(Job jobs[], int n) {
    // Sort jobs by profit descending
    for(int i=0; i<n-1; i++) {
        for(int j=0; j<n-i-1; j++) {
            if(jobs[j].profit < jobs[j+1].profit) {
                Job temp = jobs[j]; jobs[j] = jobs[j+1]; jobs[j+1] = temp;
            }
        }
    }

    int max_deadline = 0;
    for(int i=0; i<n; i++) if(jobs[i].deadline > max_deadline) max_deadline = jobs[i].deadline;

    char result[max_deadline];
    bool slot[max_deadline];
    for(int i=0; i<max_deadline; i++) slot[i] = false;

    for (int i = 0; i < n; i++) {
        for (int j = (jobs[i].deadline < max_deadline ? jobs[i].deadline : max_deadline) - 1; j >= 0; j--) {
            if (slot[j] == false) {
                result[j] = jobs[i].id;
                slot[j] = true;
                break;
            }
        }
    }
    printf("Job Sequence: ");
    for(int i=0; i<max_deadline; i++) if(slot[i]) printf("%c ", result[i]);
}

int main() {
    Job jobs[] = { {'a', 2, 100}, {'b', 1, 19}, {'c', 2, 27}, {'d', 1, 25}, {'e', 3, 15} };
    int n = sizeof(jobs)/sizeof(jobs[0]);
    jobSequencing(jobs, n);
    return 0;
}

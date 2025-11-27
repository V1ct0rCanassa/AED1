#include <stdio.h>
#include <stdlib.h>

#define MAX 1005

int main() {
    int n;
    int stack[MAX];
    int queue[MAX];
    int pq[MAX];
    int s_top, q_front, q_rear, pq_size;
    int isStack, isQueue, isPQ;
    int type, x;

    while (scanf("%d", &n) != EOF) {
        
        isStack = 1; 
        isQueue = 1; 
        isPQ = 1;

        s_top = 0;
        q_front = 0; q_rear = 0;
        pq_size = 0;

        for (int i = 0; i < n; i++) {
            scanf("%d %d", &type, &x);

            if (type == 1) {
                if (isStack) stack[s_top++] = x;
                if (isQueue) queue[q_rear++] = x;
                if (isPQ) pq[pq_size++] = x;
            } else {
                if (isStack) {
                    if (s_top == 0 || stack[--s_top] != x) {
                        isStack = 0;
                    }
                }

                if (isQueue) {
                    if (q_front == q_rear || queue[q_front++] != x) {
                        isQueue = 0;
                    }
                }

                if (isPQ) {
                    if (pq_size == 0) {
                        isPQ = 0;
                    } else {
                        int max_idx = 0;
                        int max_val = pq[0];
                        
                        for (int k = 1; k < pq_size; k++) {
                            if (pq[k] > max_val) {
                                max_val = pq[k];
                                max_idx = k;
                            }
                        }

                        if (max_val != x) {
                            isPQ = 0;
                        } else {
                            pq[max_idx] = pq[pq_size - 1];
                            pq_size--;
                        }
                    }
                }
            }
        }

        if (isStack + isQueue + isPQ > 1) {
            printf("not sure\n");
        } else if (isStack + isQueue + isPQ == 0) {
            printf("impossible\n");
        } else if (isStack) {
            printf("stack\n");
        } else if (isQueue) {
            printf("queue\n");
        } else {
            printf("priority queue\n");
        }
    }

    return 0;
}

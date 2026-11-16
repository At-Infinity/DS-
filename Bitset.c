#include <stdio.h>
#define N 10   // universe: elements 0 to 9

void display(int s[]) {
    printf("{ ");
    for (int i = 0; i < N; i++)
        if (s[i]) printf("%d ", i);
    printf("}\n");
}

void input(int s[]) {
    int n, x;
    for (int i = 0; i < N; i++) s[i] = 0;
    printf("How many elements? ");
    scanf("%d", &n);
    printf("Enter elements (0-%d): ", N - 1);
    while (n--) {
        scanf("%d", &x);
        s[x] = 1;
    }
}

int main() {
    int A[N], B[N], R[N];

    printf("Set A\n"); input(A);
    printf("Set B\n"); input(B);

    printf("\nA        = "); display(A);
    printf("B        = "); display(B);

    for (int i = 0; i < N; i++) R[i] = A[i] | B[i];
    printf("A U B    = "); display(R);

    for (int i = 0; i < N; i++) R[i] = A[i] & B[i];
    printf("A n B    = "); display(R);

    for (int i = 0; i < N; i++) R[i] = A[i] & !B[i];
    printf("A - B    = "); display(R);

    for (int i = 0; i < N; i++) R[i] = !A[i];
    printf("A'       = "); display(R);

    return 0;
}

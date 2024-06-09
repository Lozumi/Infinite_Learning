// DS Exp EC-7
// 20240526 刘黎可

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 105

int distance[MAX_SIZE][MAX_SIZE];

void floyd(int n) {
    int i, j, k;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &distance[i][j]);
        }
    }
    for (k = 1; k <= n; k++) {
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                if (distance[i][j] > distance[i][k] + distance[k][j]) {
                    distance[i][j] = distance[i][k] + distance[k][j];
                }
            }
        }
    }
}

void print_distances(int m) {
    int i, x, y;
    scanf("%d", &m);
    int temp[MAX_SIZE];
    for (i = 1; i <= m; i++) {
        scanf("%d %d", &x, &y);
        temp[i] = distance[x + 1][y + 1];
    }
    for (i = 1; i <= m; i++) {
        printf("%d\n", temp[i]);
    }
}

int main() {
    int n, m;
    scanf("%d", &n);
    floyd(n);
    print_distances(m);
    return 0;
}

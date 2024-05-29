#include <stdio.h>
#include <stdlib.h>

// 定义节点结构
typedef struct list {
    int row, col, num; // 非零元素的行号、列号及值
    struct list *down, *next; // 行和列的链表指针
} list;

// 定义十字链表结构
typedef struct crosslist {
    int mu, nu, tu; // 矩阵的行数、列数及非零元素个数
    list *headr[100], *headc[100]; // 行和列的头指针数组
} cs;

// 初始化矩阵
void init(cs *a) {
    int m, n, t1; // 输入行数、列数及非零元素个数
    scanf("%d%d%d", &m, &n, &t1);
    a->mu = m;
    a->nu = n;
    a->tu = t1;
    
    for (int i = 1; i <= m; i++) {
        a->headr[i] = NULL;
    }
    for (int i = 1; i <= n; i++) {
        a->headc[i] = NULL;
    }
}

// 创建矩阵
void create(cs *a) {
    int m, n, k, t2;
    scanf("%d", &t2);
    list *q;
    
    // 输入非零元素并插入矩阵
    for (int i = 1; i <= a->tu; i++) {
        list *p = (list *)malloc(sizeof(list));
        scanf("%d%d%d", &m, &n, &k);
        p->row = m;
        p->col = n;
        p->num = k;
        
        // 插入到行链表
        if (a->headr[m] == NULL || a->headr[m]->col > n) {
            p->next = a->headr[m];
            a->headr[m] = p;
        } else {
            for (q = a->headr[m]; q->next && q->next->col < n; q = q->next);
            p->next = q->next;
            q->next = p;
        }

        // 插入到列链表
        if (a->headc[n] == NULL || a->headc[n]->row > m) {
            p->down = a->headc[n];
            a->headc[n] = p;
        } else {
            for (q = a->headc[n]; q->down && q->down->row < m; q = q->down);
            p->down = q->down;
            q->down = p;
        }
    }

    // 处理新增的非零元素
    int flag = 0;
    for (int i = 0; i < t2; i++) {
        scanf("%d%d%d", &m, &n, &k);
        for (q = a->headr[m]; q; q = q->next) {
            if (q->col == n) {
                q->num += k;
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            list *p = (list *)malloc(sizeof(list));
            p->row = m;
            p->col = n;
            p->num = k;

            // 插入到行链表
            if (a->headr[m] == NULL || a->headr[m]->col > n) {
                p->next = a->headr[m];
                a->headr[m] = p;
            } else {
                for (q = a->headr[m]; q->next && q->next->col < n; q = q->next);
                p->next = q->next;
                q->next = p;
            }

            // 插入到列链表
            if (a->headc[n] == NULL || a->headc[n]->row > m) {
                p->down = a->headc[n];
                a->headc[n] = p;
            } else {
                for (q = a->headc[n]; q->down && q->down->row < m; q = q->down);
                p->down = q->down;
                q->down = p;
            }
        }
        flag = 0;
    }
}

// 输出矩阵
void getout(cs *a) {
    list *p;
    for (int i = 1; i <= a->mu; i++) {
        if (a->headr[i] == NULL) {
            continue;
        } else {
            p = a->headr[i];
            while (p) {
                if (p->num != 0) {
                    printf("%d %d %d\n", p->row, p->col, p->num);
                }
                p = p->next;
            }
        }
    }
}

int main() {
    cs *a = (cs *)malloc(sizeof(cs));
    init(a);
    create(a);
    getout(a);
    return 0;
}

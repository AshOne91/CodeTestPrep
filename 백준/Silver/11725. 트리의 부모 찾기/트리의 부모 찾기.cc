#include <stdio.h>

#define MAX_N 100001
#define MAX_E 200000

int head[MAX_N], to[MAX_E], nextEdge[MAX_E];
int parent[MAX_N], stack[MAX_N];
char outBuf[MAX_N * 6]; // 출력 버퍼 (최대 6자리 + 개행)
int edgeCount = 0, outLen = 0;

void addEdge(int u, int v) {
    to[edgeCount] = v;
    nextEdge[edgeCount] = head[u];
    head[u] = edgeCount++;
}

void dfs_iterative(int start) {
    int top = 0;
    stack[top++] = start;
    parent[start] = 1;

    while (top) {
        int node = stack[--top];

        for (int e = head[node]; e != -1; e = nextEdge[e]) {
            int neighbor = to[e];
            if (parent[neighbor] == 0) {
                parent[neighbor] = node;
                stack[top++] = neighbor;
            }
        }
    }
}

void fastPrintInt(int x) {
    char buf[6];
    int len = 0;
    while (x) {
        buf[len++] = '0' + (x % 10);
        x /= 10;
    }
    while (len--) outBuf[outLen++] = buf[len];
    outBuf[outLen++] = '\n';
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 1; i <= n; ++i)
        head[i] = -1;

    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        addEdge(a, b);
        addEdge(b, a);
    }

    dfs_iterative(1);

    for (int i = 2; i <= n; ++i)
        fastPrintInt(parent[i]);

    fwrite(outBuf, 1, outLen, stdout);
    return 0;
}

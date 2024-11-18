#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

const int MAX = 100000;
int head[MAX + 1], to[MAX * 2], nextEdge[MAX * 2], parents[MAX + 1];
int edgeCount = 0;

// 메모리를 덜 쓰는 그래프 연결 방식 (Adjacency List 직접 구현)
void addEdge(int u, int v) {
    to[edgeCount] = v;
    nextEdge[edgeCount] = head[u];
    head[u] = edgeCount++;
}

void dfs(int node) {
    for (int edge = head[node]; edge != -1; edge = nextEdge[edge]) {
        int neighbor = to[edge];
        if (parents[neighbor] == 0) { // 아직 방문하지 않음
            parents[neighbor] = node;
            dfs(neighbor);
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    // 초기화
    memset(head, -1, sizeof(head));

    // 입력 처리 및 간선 추가
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        addEdge(a, b);
        addEdge(b, a);
    }

    // DFS로 부모 찾기
    parents[1] = 1; // 루트 노드 설정
    dfs(1);

    // 결과 출력
    for (int i = 2; i <= n; ++i) {
        printf("%d\n", parents[i]);
    }

    return 0;
}

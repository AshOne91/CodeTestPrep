#include <stdio.h>

int board[128][128];
int ans[2];  // ans[0] - white, ans[1] - blue

// 색이 모두 동일한지 확인
int check(int n, int x, int y) {
    int color = board[x][y];  // 첫 번째 색을 저장
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (board[x + i][y + j] != color) {
                return 0;  // 색이 다르면 0 반환
            }
        }
    }
    return 1;  // 색이 모두 같으면 1 반환
}

// 분할 정복을 이용한 색 종이 카운트
void solve(int n, int x, int y) {
    if (check(n, x, y)) {  // 동일한 색이면 바로 카운트
        ans[board[x][y]]++;
    } else {
        int half = n / 2;
        solve(half, x, y);  // 좌상
        solve(half, x + half, y);  // 우상
        solve(half, x, y + half);  // 좌하
        solve(half, x + half, y + half);  // 우하
    }
}

int main() {
    int n;
    scanf("%d", &n);
    
    // 빠른 입력 처리
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &board[i][j]);
        }
    }

    solve(n, 0, 0);

    printf("%d\n%d\n", ans[0], ans[1]);
    return 0;
}

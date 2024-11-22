#include <cstdio>

const int MAX_N = 1024;
int sum[MAX_N + 1][MAX_N + 1];

// 빠른 입력 함수
inline int fastInput() {
    int x = 0, c;
    while ((c = getchar_unlocked()) < '0');
    do { x = x * 10 + (c - '0'); } while ((c = getchar_unlocked()) >= '0');
    return x;
}

// 빠른 출력 함수
inline void fastOutput(int x) {
    char buf[12];
    int idx = 0;
    if (x == 0) buf[idx++] = '0';
    while (x > 0) {
        buf[idx++] = (x % 10) + '0';
        x /= 10;
    }
    while (idx--) putchar_unlocked(buf[idx]);
    putchar_unlocked('\n');
}

int main() {
    int N = fastInput();
    int M = fastInput();

    // 누적 합 배열 생성
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            int value = fastInput();
            sum[i][j] = value + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
        }
    }

    // 쿼리 처리
    while (M--) {
        int x1 = fastInput();
        int y1 = fastInput();
        int x2 = fastInput();
        int y2 = fastInput();

        int result = sum[x2][y2]
                     - (x1 > 1 ? sum[x1 - 1][y2] : 0)
                     - (y1 > 1 ? sum[x2][y1 - 1] : 0)
                     + (x1 > 1 && y1 > 1 ? sum[x1 - 1][y1 - 1] : 0);

        fastOutput(result);
    }

    return 0;
}

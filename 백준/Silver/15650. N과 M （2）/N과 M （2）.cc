#include <iostream>

int N, M;
void backtrack(int s, int d, int* r) {
    if (d == M) {
        for (int i = 0; i < M; i++) std::cout << r[i] << ' ';
        std::cout << '\n';
        return;
    }
    for (int i = s; i <= N; i++) {
        r[d] = i;
        backtrack(i + 1, d + 1, r);
    }
}

int main() {
    std::cin >> N >> M;
    int r[8] = {}; // M <= 8 가정
    backtrack(1, 0, r);
}

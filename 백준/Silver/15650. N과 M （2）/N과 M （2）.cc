#include <iostream>

int N, M, comb[8];

void bt(int idx, int cnt) {
    if (cnt == M) {
        for (int i = 0; i < M; ++i) std::cout << comb[i] << ' ';
        std::cout << '\n';
        return;
    }
    for (int i = idx; i <= N; ++i) {
        comb[cnt] = i;
        bt(i + 1, cnt + 1);
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cin >> N >> M;
    bt(1, 0);
}

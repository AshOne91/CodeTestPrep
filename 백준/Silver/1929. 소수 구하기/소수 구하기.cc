#include<iostream>
#include<vector>

int main() {
    std::ios::sync_with_stdio(false);  // 입출력 속도 최적화
    std::cin.tie(NULL);                // 입출력 묶음 해제
    std::cout.tie(NULL);               // 입출력 묶음 해제

    int m, n;
    std::cin >> m >> n;

    std::vector<bool> board(n + 1, false);  // 최대 n까지의 소수를 구할 수 있도록 배열 크기 설정
    
    // 에라토스테네스의 체 알고리즘으로 소수 구하기
    for (int i = 2; i * i <= n; ++i) {
        if (board[i] == false) {  // i가 소수이면
            for (int j = i * i; j <= n; j += i) {  // i의 배수를 모두 true로 설정
                board[j] = true;
            }
        }
    }

    // 소수 출력
    for (int i = std::max(2, m); i <= n; ++i) {  // m이 2보다 작으면 2부터 출력
        if (board[i] == false) {  // false인 경우 소수
            std::cout << i << "\n";
        }
    }

    return 0;
}
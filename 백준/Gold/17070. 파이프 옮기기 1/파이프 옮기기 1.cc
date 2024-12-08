#include <iostream>
#include <vector>

using namespace std;

int N;
vector<vector<int>> grid;
vector<vector<vector<int>>> dp;

int main() {
    // 입력 받기
    cin >> N;
    grid.assign(N, vector<int>(N));
    dp.assign(N, vector<vector<int>>(N, vector<int>(3, 0))); // 가로(0), 세로(1), 대각선(2)

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }

    // 초기 상태 설정
    dp[0][1][0] = 1; // 시작 상태: (1,1)-(1,2) 가로 방향

    // DP 계산
    for (int i = 0; i < N; i++) {
        for (int j = 1; j < N; j++) {
            if (grid[i][j] == 1) continue;

            // 가로 방향에서의 이동
            if (j - 1 >= 0) {
                dp[i][j][0] += dp[i][j - 1][0]; // 이전 가로
                dp[i][j][0] += dp[i][j - 1][2]; // 이전 대각선
            }

            // 세로 방향에서의 이동
            if (i - 1 >= 0) {
                dp[i][j][1] += dp[i - 1][j][1]; // 이전 세로
                dp[i][j][1] += dp[i - 1][j][2]; // 이전 대각선
            }

            // 대각선 방향에서의 이동
            if (i - 1 >= 0 && j - 1 >= 0) {
                if (grid[i - 1][j] == 0 && grid[i][j - 1] == 0) {
                    dp[i][j][2] += dp[i - 1][j - 1][0]; // 이전 가로
                    dp[i][j][2] += dp[i - 1][j - 1][1]; // 이전 세로
                    dp[i][j][2] += dp[i - 1][j - 1][2]; // 이전 대각선
                }
            }
        }
    }

    // 결과 출력
    int result = dp[N - 1][N - 1][0] + dp[N - 1][N - 1][1] + dp[N - 1][N - 1][2];
    cout << result << endl;

    return 0;
}

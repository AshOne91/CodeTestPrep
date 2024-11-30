#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;

        vector<vector<int>> score(2, vector<int>(n));
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < n; j++) {
                cin >> score[i][j];
            }
        }

        if (n == 1) {
            cout << max(score[0][0], score[1][0]) << '\n';
            continue;
        }

        // DP 배열 초기화
        vector<vector<int>> dp(2, vector<int>(n, 0));
        dp[0][0] = score[0][0];
        dp[1][0] = score[1][0];
        dp[0][1] = score[1][0] + score[0][1];
        dp[1][1] = score[0][0] + score[1][1];

        for (int i = 2; i < n; i++) {
            dp[0][i] = score[0][i] + max(dp[1][i-1], dp[1][i-2]);
            dp[1][i] = score[1][i] + max(dp[0][i-1], dp[0][i-2]);
        }

        cout << max(dp[0][n-1], dp[1][n-1]) << '\n';
    }
    return 0;
}

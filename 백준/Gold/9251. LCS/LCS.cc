#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int longest_common_subsequence(const string& str1, const string& str2) {
    int n = str1.size();
    int m = str2.size();

    // DP 테이블 초기화
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // DP 채우기
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (str1[i - 1] == str2[j - 1]) { // 문자가 같은 경우
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else { // 문자가 다른 경우
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // 최종 결과 반환
    return dp[n][m];
}

int main() {
    string str1, str2;
    cin >> str1 >> str2;

    // LCS 길이 출력
    cout << longest_common_subsequence(str1, str2) << endl;

    return 0;
}

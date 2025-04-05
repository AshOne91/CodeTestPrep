#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, res = 1;
    cin >> n;
    vector<int> v(n), dp(n, 1);
    for (int i = 0; i < n; ++i) cin >> v[i];
    for (int i = 1; i < n; ++i)
        for (int j = 0; j < i; ++j)
            if (v[i] > v[j]) dp[i] = max(dp[i], dp[j] + 1);
    for (int i = 0; i < n; ++i) res = max(res, dp[i]);
    cout << res;
}

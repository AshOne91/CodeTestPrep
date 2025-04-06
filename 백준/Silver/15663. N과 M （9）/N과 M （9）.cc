#include <bits/stdc++.h>
using namespace std;

int N, M, a[8];
bool v[8];
vector<int> r;

void dfs() {
    if ((int)r.size() == M) {
        for (int x : r) cout << x << ' ';
        cout << '\n';
        return;
    }
    int last = -1;
    for (int i = 0; i < N; ++i) {
        if (v[i] || a[i] == last) continue;
        v[i] = true;
        r.push_back(last = a[i]);
        dfs();
        v[i] = false;
        r.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; ++i) cin >> a[i];
    sort(a, a + N);
    dfs();
}

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    while (cin >> s && s != "0") {
        bool is_pal = true;
        size_t l = 0, r = s.size() - 1;
        while (l < r) {
            if (s[l] != s[r]) { is_pal = false; break; }
            ++l; --r;
        }
        cout << (is_pal ? "yes" : "no") << '\n';
    }
    return 0;
}

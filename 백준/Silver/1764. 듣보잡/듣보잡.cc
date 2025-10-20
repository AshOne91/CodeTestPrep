#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    unordered_set<string> notHeard;

    // Read N names (not heard)
    for (int i = 0; i < N; i++) {
        string name;
        cin >> name;
        notHeard.insert(name);
    }

    // Find names that are both not heard AND not seen
    vector<string> result;
    for (int i = 0; i < M; i++) {
        string name;
        cin >> name;
        if (notHeard.count(name)) {
            result.push_back(name);
        }
    }

    // Sort the result
    sort(result.begin(), result.end());

    // Output
    cout << result.size() << '\n';
    for (const auto& name : result) {
        cout << name << '\n';
    }

    return 0;
}
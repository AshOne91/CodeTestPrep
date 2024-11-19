#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> values;
vector<int> sequence;  // 현재 선택한 수열
vector<bool> visited;  // 방문 여부를 동적으로 관리

void backtracking(int depth) {
    if (depth == M) {  // 수열 길이가 M이면 출력
        for (int num : sequence) {
            cout << num << " ";
        }
        cout << "\n";
        return;
    }

    int prev = -1; // 이전에 사용한 숫자 기록 (중복 방지)
    for (int i = 0; i < N; i++) {
        if (!visited[i] && values[i] != prev) {
            visited[i] = true;
            sequence.push_back(values[i]);
            backtracking(depth + 1);
            sequence.pop_back();
            visited[i] = false;
            prev = values[i]; // 이전 값 갱신
        }
    }
}

int main() {
    cin >> N >> M;
    values.resize(N);
    visited.resize(N, false);  // 방문 여부 동적 초기화

    for (int i = 0; i < N; i++) {
        cin >> values[i];
    }

    sort(values.begin(), values.end());  // 사전순 정렬
    backtracking(0);

    return 0;
}

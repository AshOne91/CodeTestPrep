#include <iostream>
#include <queue>
using namespace std;

int main() {
    /*
    Fast I/O

    N이 최대 5,000으로 작지만
    습관적으로 사용
    */
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    cin >> N >> K;

    queue<int> q;
    for (int i = 1; i <= N; i++) {
        q.push(i);
    }

    cout << "<";
    bool first = true;  // 첫 번째 원소 체크

    while (!q.empty()) {
        for (int i = 0; i < K - 1; i++) {
            q.push(q.front());  // 맨 앞을 맨 뒤로
            q.pop();            // 맨 앞 제거
        }

        if (!first) {
            cout << ", ";
        }
        cout << q.front();  // K번째 사람 출력
        q.pop();            // 제거

        first = false;
    }

    cout << ">";
    return 0;
}
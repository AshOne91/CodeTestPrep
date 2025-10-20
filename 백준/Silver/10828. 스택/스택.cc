#include <iostream>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    stack<int> st;
    while (N--) {
        string cmd;
        cin >> cmd;

        // CASE 1: 'p'로 시작 (push or pop)
        if (cmd[0] == 'p') {
            if (cmd[1] == 'u') {  // push
                int x;
                cin >> x;
                st.push(x);
            } else {
                if (st.empty()) {
                    cout << -1 << '\n';
                } else {
                    cout << st.top() << '\n';
                    st.pop();
                }
            }
        }
        // CASE 2: size
        else if (cmd[0] == 's') {
            cout << st.size() << '\n';
        }
        // CASE 3: empty
        else if (cmd[0] == 'e') {
            cout << (st.empty() ? 1 : 0) << '\n';
        }
        // CASE 4: top
        else {
            cout << (st.empty() ? -1 : st.top()) << '\n';
        }
    }

    return 0;
}
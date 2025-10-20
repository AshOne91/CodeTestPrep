#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int M;
    cin >> M;

    int S = 0;

    while (M--) {
        string cmd;
        cin >> cmd;

        if (cmd[0] == 'a') {
            if (cmd[1] == 'd') {
                int x;
                cin >> x;
                S |= (1 << x);
            } else {
                S = (1 << 21) - 1;
            }
        } else if (cmd[0] == 'r') {
            int x;
            cin >> x;
            S &= ~(1 << x);
        } else if (cmd[0] == 'c') {
            int x;
            cin >> x;
            cout << ((S & (1 << x)) ? 1 : 0) << '\n';
        } else if (cmd[0] == 't') {
            int x;
            cin >> x;
            S ^= (1 << x);
        } else {
            S = 0;
        }
    }

    return 0;
}

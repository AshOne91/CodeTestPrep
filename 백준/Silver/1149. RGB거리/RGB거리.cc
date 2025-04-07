#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    int prevR = 0, prevG = 0, prevB = 0;

    while (N--) {
        int R, G, B;
        cin >> R >> G >> B;

        int nextR = R + min(prevG, prevB);
        int nextG = G + min(prevR, prevB);
        int nextB = B + min(prevR, prevG);

        prevR = nextR;
        prevG = nextG;
        prevB = nextB;
    }

    cout << min({prevR, prevG, prevB}) << '\n';
    return 0;
}

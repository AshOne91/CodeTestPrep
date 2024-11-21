#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    int prevR = 0, prevG = 0, prevB = 0; // 이전 집의 최솟값 저장
    for (int i = 0; i < N; ++i) {
        int R, G, B;
        cin >> R >> G >> B;

        // 현재 비용 계산 (이전 값 기반으로 업데이트)
        int currR = R + min(prevG, prevB);
        int currG = G + min(prevR, prevB);
        int currB = B + min(prevR, prevG);

        // 이전 값을 현재 값으로 업데이트
        prevR = currR;
        prevG = currG;
        prevB = currB;
    }

    // 결과 출력: 마지막 집의 최소 비용
    cout << min({prevR, prevG, prevB}) << '\n';
    return 0;
}

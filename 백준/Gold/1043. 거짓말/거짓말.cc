#include <iostream>
#include <vector>
#include <queue>
#include <set>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int N, M;
    std::cin >> N >> M;

    std::vector<bool> knowsTruth(N + 1, false); // 진실을 아는 사람 여부
    std::vector<std::vector<int>> parties(M);  // 파티 정보
    std::vector<std::vector<int>> partyGraph(N + 1); // 사람과 파티 연결 그래프

    int numTruth, person;
    std::cin >> numTruth;

    // 진실을 아는 사람들 초기화
    std::queue<int> q; // 진실 전파를 위한 큐
    for (int i = 0; i < numTruth; ++i) {
        std::cin >> person;
        knowsTruth[person] = true;
        q.push(person);
    }

    // 파티 정보와 연결 그래프 생성
    for (int i = 0; i < M; ++i) {
        int numPeople;
        std::cin >> numPeople;
        for (int j = 0; j < numPeople; ++j) {
            std::cin >> person;
            parties[i].push_back(person);
            partyGraph[person].push_back(i);
        }
    }

    // 진실 전파 (BFS)
    std::vector<bool> visitedParties(M, false);
    while (!q.empty()) {
        int current = q.front();
        q.pop();

        for (int party : partyGraph[current]) {
            if (visitedParties[party]) continue;
            visitedParties[party] = true;

            for (int participant : parties[party]) {
                if (!knowsTruth[participant]) {
                    knowsTruth[participant] = true;
                    q.push(participant);
                }
            }
        }
    }

    // 거짓말할 수 있는 파티 계산
    int result = 0;
    for (int i = 0; i < M; ++i) {
        bool canLie = true;
        for (int participant : parties[i]) {
            if (knowsTruth[participant]) {
                canLie = false;
                break;
            }
        }
        if (canLie) {
            ++result;
        }
    }

    std::cout << result;
}

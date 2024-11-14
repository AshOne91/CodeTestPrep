#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> sequence;

void backtrack(int start) {
    // 현재 길이가 M이라면 수열을 출력합니다.
    if (sequence.size() == M) {
        for (int num : sequence)
            cout << num << " ";
        cout << "\n";
        return;
    }
    
    // start부터 N까지의 숫자를 선택합니다.
    for (int i = start; i <= N; ++i) {
        sequence.push_back(i); // 숫자를 추가
        backtrack(i);          // i부터 다시 시작하여 비내림차순 유지
        sequence.pop_back();    // 백트래킹: 선택을 취소
    }
}

int main() {
    std::ios::sync_with_stdio(false);  // 입출력 속도 최적화
    std::cin.tie(NULL);                // 입출력 묶음 해제
    std::cout.tie(NULL);        
    
    cin >> N >> M;
    backtrack(1); // 1부터 시작
    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int count;
    std::cin >> count;

    if (count == 1) {
        int score;
        std::cin >> score;
        std::cout << score << "\n";
        return 0;
    }

    std::vector<int> stairPoint(count);
    for (int i = 0; i < count; ++i) {
        std::cin >> stairPoint[i];
    }

    // DP 배열 초기화
    std::vector<int> stairMaxPoint(count, 0);
    stairMaxPoint[0] = stairPoint[0];
    stairMaxPoint[1] = stairPoint[0] + stairPoint[1];
    
    // 두 번째 계단까지 초기값 설정
    for (int i = 2; i < count; ++i) {
        stairMaxPoint[i] = std::max(stairMaxPoint[i - 2] + stairPoint[i], 
                                    stairMaxPoint[i - 3] + stairPoint[i - 1] + stairPoint[i]);
    }

    std::cout << stairMaxPoint[count - 1] << "\n";
    return 0;
}
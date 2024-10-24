#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int main() {
    int n;
    std::cin >> n;  // n을 입력받아 초기화
    
    if (n == 0) {
        std::cout << 0;
        return 0;
    }

    std::vector<int> values;
    for (int i = 0; i < n; ++i) {
        int num;
        std::cin >> num;
        values.push_back(num);
    }

    std::sort(values.begin(), values.end());

    // 15% 값을 반올림하여 check 값 계산
    int check = std::round(n * 0.15);

    double total = 0;
    for (int i = check; i < n - check; ++i) {
        total += values[i];
    }

    // 평균을 계산한 후 반올림하여 출력
    std::cout << std::round(total / (n - check * 2)) << std::endl;

    return 0;
}
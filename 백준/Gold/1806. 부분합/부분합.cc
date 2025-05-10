#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N, S;
    std::cin >> N >> S;
    std::vector<int> arr(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> arr[i];
    }

    int min_len = N + 1; 
    int sum = 0;
    int left = 0;

    for (int right = 0; right < N; ++right) {
        sum += arr[right];

        while (sum >= S) 
        {
            min_len = std::min(min_len, right - left + 1);
            sum -= arr[left];
            left++;
        }
    }

    if (min_len == N + 1) {
        std::cout << 0;
    } else {
        std::cout << min_len;
    }
}

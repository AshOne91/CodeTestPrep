#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>

using namespace std;

// 치킨 거리 계산 함수
int calculate_chicken_distance(const vector<pair<int, int>>& houses, const vector<pair<int, int>>& selected_chickens) {
    int total_distance = 0;
    for (const auto& [hx, hy] : houses) {
        int min_distance = INT_MAX;
        for (const auto& [cx, cy] : selected_chickens) {
            min_distance = min(min_distance, abs(hx - cx) + abs(hy - cy));
        }
        total_distance += min_distance;
    }
    return total_distance;
}

// 메인 함수
int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> houses, chicken_shops;

    // 입력 처리 및 좌표 저장
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int cell;
            cin >> cell;
            if (cell == 1) houses.emplace_back(i, j);
            else if (cell == 2) chicken_shops.emplace_back(i, j);
        }
    }

    // 치킨집 조합 생성
    vector<int> indices(chicken_shops.size(), 1);
    fill(indices.begin(), indices.begin() + (chicken_shops.size() - m), 0);

    int min_city_distance = INT_MAX;
    do {
        vector<pair<int, int>> selected_chickens;
        for (size_t i = 0; i < chicken_shops.size(); ++i) {
            if (indices[i]) {
                selected_chickens.push_back(chicken_shops[i]);
            }
        }
        // 도시의 치킨 거리 계산 및 최소값 갱신
        min_city_distance = min(min_city_distance, calculate_chicken_distance(houses, selected_chickens));
    } while (next_permutation(indices.begin(), indices.end()));

    // 결과 출력
    cout << min_city_distance << endl;

    return 0;
}

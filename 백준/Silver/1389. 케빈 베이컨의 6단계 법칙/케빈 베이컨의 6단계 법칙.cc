#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1e9; // 무한대 값으로 사용할 큰 수

int main() {
    int n, m;
    cin >> n >> m;
    
    // 거리 배열 초기화
    vector<vector<int>> dist(n, vector<int>(n, INF));
    
    // 자신과의 거리는 0으로 설정
    for (int i = 0; i < n; ++i) {
        dist[i][i] = 0;
    }
    
    // 친구 관계 입력
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        a--; b--;  // 0부터 시작하는 인덱스 사용
        dist[a][b] = 1;
        dist[b][a] = 1;
    }
    
    // 플로이드-워셜 알고리즘
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dist[i][k] != INF && dist[k][j] != INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
    
    // 케빈 베이컨 수가 가장 작은 사람 찾기
    int min_kevin_bacon = INF;
    int person = -1;
    
    for (int i = 0; i < n; ++i) {
        int kevin_bacon = 0;
        for (int j = 0; j < n; ++j) {
            kevin_bacon += dist[i][j];
        }
        if (kevin_bacon < min_kevin_bacon) {
            min_kevin_bacon = kevin_bacon;
            person = i;
        }
    }
    
    // 결과 출력 (1부터 시작하는 인덱스로 출력)
    cout << person + 1 << endl;
    
    return 0;
}
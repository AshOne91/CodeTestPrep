#include <iostream>

#define MAX 1001
int map[MAX][MAX], queue[MAX * MAX][2], front = 0, rear = 0;
int dy[4] = {-1, 1, 0, 0}, dx[4] = {0, 0, 1, -1};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int M, N;
    std::cin >> M >> N;
    
    bool allRipe = true;
    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < M; ++x) {
            std::cin >> map[y][x];
            if (map[y][x] == 1) queue[rear][0] = y, queue[rear++][1] = x;
            if (map[y][x] == 0) allRipe = false;
        }
    }
    
    if (allRipe) return std::cout << "0\n", 0;
    
    int days = -1;
    while (front < rear) {
        int size = rear - front;
        while (size--) {
            int y = queue[front][0], x = queue[front++][1];
            for (int i = 0; i < 4; ++i) {
                int ny = y + dy[i], nx = x + dx[i];
                if (ny < 0 || nx < 0 || ny >= N || nx >= M || map[ny][nx] != 0) continue;
                map[ny][nx] = 1;
                queue[rear][0] = ny, queue[rear++][1] = nx;
            }
        }
        ++days;
    }
    
    for (int y = 0; y < N; ++y)
        for (int x = 0; x < M; ++x)
            if (map[y][x] == 0) return std::cout << "-1\n", 0;
    
    std::cout << days << "\n";
    return 0;
}

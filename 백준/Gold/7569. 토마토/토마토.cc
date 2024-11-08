#include <iostream>
#include <queue>

struct Point {
    int x, y, z;
    Point(int x, int y, int z) : x(x), y(y), z(z) {}
};

int map[101][101][101];
int dist[101][101][101];
int dz[6] = {-1, 1, 0, 0, 0, 0};
int dy[6] = {0, 0, -1, 1, 0, 0};
int dx[6] = {0, 0, 0, 0, -1, 1};

int main() {
    std::ios::sync_with_stdio(false);  
    std::cin.tie(NULL);               
    std::cout.tie(NULL);               

    int M, N, H;
    std::cin >> M >> N >> H;
    std::queue<Point> qu;

    for (int z = 0; z < H; ++z) {
        for (int y = 0; y < N; ++y) {
            for (int x = 0; x < M; ++x) {
                std::cin >> map[z][y][x];
                dist[z][y][x] = -1; // 초기값을 -1로 설정
                if (map[z][y][x] == 1) {
                    qu.push({x, y, z});
                    dist[z][y][x] = 0; // 시작 위치의 거리는 0
                }
            }
        }
    }

    int lastDist = 0;
    while (!qu.empty()) {
        Point point = qu.front();
        qu.pop();

        for (int dir = 0; dir < 6; ++dir) {
            int nextZ = dz[dir] + point.z;
            int nextY = dy[dir] + point.y;
            int nextX = dx[dir] + point.x;

            if (nextZ < 0 || nextY < 0 || nextX < 0
                || nextX >= M || nextY >= N || nextZ >= H
                || map[nextZ][nextY][nextX] == -1
                || dist[nextZ][nextY][nextX] != -1) {
                continue;
            }

            map[nextZ][nextY][nextX] = 1;
            dist[nextZ][nextY][nextX] = dist[point.z][point.y][point.x] + 1;
            lastDist = dist[nextZ][nextY][nextX];
            qu.push({nextX, nextY, nextZ});
        }
    }

    for (int z = 0; z < H; ++z) {
        for (int y = 0; y < N; ++y) {
            for (int x = 0; x < M; ++x) {
                if (map[z][y][x] == 0) {
                    std::cout << -1;
                    return 0;
                }
            }
        }
    }

    std::cout << lastDist;
    return 0;
}

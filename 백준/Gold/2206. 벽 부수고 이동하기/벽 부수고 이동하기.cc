#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <limits>

const int INF = std::numeric_limits<int>::max();
std::vector<std::pair<int, int>> dirs{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    
    int N, M;
    std::cin >> N >> M;
    std::vector<std::vector<int>> map(N, std::vector<int>(M, 0));
    for (int y = 0; y < N; ++y)
    {
        std::string line;
        std::cin >> line;
        for (int x = 0; x < M; ++x)
        {
            map[y][x] = line[x] - '0';
        }
    }

    // distance[y][x][0] : 벽 안 뚫고 이동한 거리
    // distance[y][x][1] : 벽 뚫고 이동한 거리
    std::vector<std::vector<std::vector<int>>> distance(N, std::vector<std::vector<int>>(M, std::vector<int>(2, INF)));

    std::queue<std::tuple<int, int, int>> q; // y, x, 벽 부쉈는지 여부(0 or 1)
    q.push({0, 0, 0});
    distance[0][0][0] = 1; // 시작점 거리 1

    while (!q.empty())
    {
        auto [current_y, current_x, broken] = q.front();
        q.pop();

        for (auto& dir : dirs)
        {
            int next_y = current_y + dir.first;
            int next_x = current_x + dir.second;

            // 범위 벗어나면 skip
            if (next_y < 0 || next_y >= N || next_x < 0 || next_x >= M)
                continue;

            // 이동할 곳이 벽인 경우
            if (map[next_y][next_x] == 1 && broken == 0)
            {
                // 벽을 부수고 이동
                if (distance[next_y][next_x][1] == INF)
                {
                    distance[next_y][next_x][1] = distance[current_y][current_x][0] + 1;
                    q.push({next_y, next_x, 1});
                }
            }
            // 이동할 곳이 벽이 아닌 경우
            else if (map[next_y][next_x] == 0)
            {
                if (distance[next_y][next_x][broken] == INF)
                {
                    distance[next_y][next_x][broken] = distance[current_y][current_x][broken] + 1;
                    q.push({next_y, next_x, broken});
                }
            }
        }
    }

    int result = std::min(distance[N - 1][M - 1][0], distance[N - 1][M - 1][1]);
    if (result == INF)
        std::cout << -1 << "\n";
    else
        std::cout << result << "\n";
}

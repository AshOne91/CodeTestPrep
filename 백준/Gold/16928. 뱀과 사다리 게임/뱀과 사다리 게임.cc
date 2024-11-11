#include <iostream>
#include <queue>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N, M, start, end;
    std::cin >> N >> M;

    int warp[101];
    bool visited[101] = {false};
    for (int i = 1; i <= 100; ++i) warp[i] = i;

    while (N--) std::cin >> start >> end, warp[start] = end;
    while (M--) std::cin >> start >> end, warp[start] = end;

    std::queue<std::pair<int, int>> q;
    q.push({1, 0});
    visited[1] = true;

    while (!q.empty())
    {
        auto [pos, moves] = q.front(); q.pop();
        if (pos == 100) { std::cout << moves; return 0; }

        for (int i = 1; i <= 6; ++i)
        {
            int next = warp[pos + i];
            if (next <= 100 && !visited[next])
            {
                visited[next] = true;
                q.push({next, moves + 1});
            }
        }
    }
    return 0;
}

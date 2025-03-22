#include <iostream>
#include <vector>
#include <stack>

std::vector<std::pair<int, int>> dir{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int T;
    std::cin >> T;

    for (int i = 0; i < T; ++i)
    {
        int M, N, K;
        std::cin >> M >> N >> K;
        std::vector<std::vector<int>> map(N, std::vector<int>(M, 0));
        int count = 0;
        std::stack<std::pair<int, int>> st;

        for (int j = 0; j < K; ++j)
        {
            int X, Y;
            std::cin >> X >> Y;
            map[Y][X] = 1;
        }

        for (int y = 0; y < N; ++y)
        {
            for (int x = 0; x < M; ++x)
            {
                if (map[y][x] == 0)
                {
                    continue;
                }
                st.push({y, x});
                map[y][x] = 0;
                count++;

                while (!st.empty())
                {
                    auto pos = st.top();
                    st.pop();
                    
                    for (auto& d : dir)
                    {
                        int ny = pos.first + d.first;
                        int nx = pos.second + d.second;

                        if (ny >= 0 && ny < N && nx >= 0 && nx < M && map[ny][nx] == 1)
                        {
                            st.push({ny, nx});
                            map[ny][nx] = 0;
                        }
                    }
                }
            }
        }

        std::cout << count << "\n";
    }
}

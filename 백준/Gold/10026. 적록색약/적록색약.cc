#include <iostream>
#include <stack>
#include <string>
#include <vector>

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

inline bool isInBounds(int x, int y, int N) {
    return x >= 0 && x < N && y >= 0 && y < N;
}

void dfs(int start, const char* map, char* visited, int N, char color) {
    std::stack<int> stack;
    stack.push(start);
    visited[start] = 1;

    while (!stack.empty()) {
        int pos = stack.top();
        stack.pop();

        int x = pos / N, y = pos % N;
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int npos = nx * N + ny;
            if (isInBounds(nx, ny, N) && !visited[npos] && map[npos] == color) {
                visited[npos] = 1;
                stack.push(npos);
            }
        }
    }
}

int countRegions(const char* map, int N) {
    std::vector<char> visited(N * N, 0);
    int count = 0;

    for (int i = 0; i < N * N; ++i) {
        if (!visited[i]) {
            dfs(i, map, visited.data(), N, map[i]);
            count++;
        }
    }
    return count;
}

int main() {
    int N;
    std::cin >> N;
    std::vector<char> normalMap(N * N);
    std::vector<char> rgMap(N * N);

    for (int i = 0; i < N; ++i) {
        std::string str;
        std::cin >> str;
        for (int j = 0; j < N; ++j) {
            char color = str[j];
            normalMap[i * N + j] = color;
            rgMap[i * N + j] = (color == 'R' || color == 'G') ? 'C' : color;
        }
    }

    int normalCount = countRegions(normalMap.data(), N);
    int rgCount = countRegions(rgMap.data(), N);

    std::cout << normalCount << " " << rgCount << std::endl;
    return 0;
}

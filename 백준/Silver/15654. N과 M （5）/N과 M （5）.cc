#include <iostream>
#include <vector>
#include <algorithm>

int N, M;
std::vector<int> values;
std::vector<bool> visited;

void backtracking(std::vector<int>& result)
{
    // 길이가 M인 수열을 완성하면 출력
    if (static_cast<int>(result.size()) == M)
    {
        for (size_t i = 0; i < result.size(); ++i)
        {
            if (i > 0) std::cout << " ";
            std::cout << result[i];
        }
        std::cout << "\n";
        return;
    }

    // 순열 생성
    for (int i = 0; i < N; ++i)
    {
        if (!visited[i]) // 이미 사용한 값은 제외
        {
            visited[i] = true;          // 방문 표시
            result.push_back(values[i]); // 값 추가
            backtracking(result);       // 다음 단계 진행
            result.pop_back();          // 백트래킹
            visited[i] = false;         // 방문 해제
        }
    }
}

int main()
{
    std::cin >> N >> M;
    values.resize(N);
    visited.resize(N, false);

    for (int i = 0; i < N; ++i)
    {
        std::cin >> values[i];
    }

    std::sort(values.begin(), values.end()); // 사전 순 정렬

    std::vector<int> result;
    backtracking(result); // 백트래킹 시작

    return 0;
}

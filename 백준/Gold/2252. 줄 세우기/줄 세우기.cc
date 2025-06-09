#include <iostream>
#include <vector>
#include <queue>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N, M; // N: 학생 수, M: 비교 횟수
    std::cin >> N >> M;

    std::vector<std::vector<int>> adj(N + 1); // 인접 리스트
    std::vector<int> indegree(N + 1, 0);      // 진입 차수

    // 비교 정보 입력 (A는 B 앞에 서야 함)
    for (int i = 0; i < M; ++i)
    {
        int A, B;
        std::cin >> A >> B;
        adj[A].push_back(B);  // A → B
        indegree[B]++;        // B의 진입 차수 증가
    }

    std::queue<int> q;
    std::vector<int> result;

    // 진입 차수가 0인 학생 먼저 줄 세움
    for (int i = 1; i <= N; ++i)
    {
        if (indegree[i] == 0)
            q.push(i);
    }

    // 위상 정렬 수행
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        result.push_back(cur); // 줄에 추가

        // 연결된 다음 학생들 진입 차수 감소
        for (int next : adj[cur])
        {
            indegree[next]--;
            if (indegree[next] == 0)
                q.push(next);
        }
    }

    // 결과 출력
    for (int x : result)
    {
        std::cout << x << ' ';
    }
    std::cout << '\n';

    return 0;
}

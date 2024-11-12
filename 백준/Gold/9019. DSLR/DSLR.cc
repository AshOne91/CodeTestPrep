#include <iostream>
#include <vector>
#include <queue>

int visited[10000];
int visit_count = 1;

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    
    int T;
    std::cin >> T;
    while (T--)
    {
        std::queue<std::pair<int, std::string>> qu;
        int A, B;
        std::cin >> A >> B;
        
        qu.push({A, ""});
        visited[A] = visit_count;

        while (!qu.empty())
        {
            auto [num, cmd] = qu.front();
            qu.pop();
            
            if (num == B)
            {
                std::cout << cmd << "\n";
                break;
            }
            
            int D = (num * 2) % 10000;
            if (visited[D] != visit_count)
            {
                visited[D] = visit_count;
                qu.push({D, cmd + 'D'});
            }

            int S = num == 0 ? 9999 : num - 1;
            if (visited[S] != visit_count)
            {
                visited[S] = visit_count;
                qu.push({S, cmd + 'S'});
            }

            int L = (num % 1000) * 10 + (num / 1000);
            if (visited[L] != visit_count)
            {
                visited[L] = visit_count;
                qu.push({L, cmd + 'L'});
            }

            int R = (num / 10) + (num % 10) * 1000;
            if (visited[R] != visit_count)
            {
                visited[R] = visit_count;
                qu.push({R, cmd + 'R'});
            }
        }
        visit_count++;  // 다음 테스트 케이스에서 새 visit_count 사용
    }
}

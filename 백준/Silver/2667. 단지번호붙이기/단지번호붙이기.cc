#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<string>

std::vector<std::pair<int, int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int main()
{
    std::ios::sync_with_stdio(false);  // 입출력 속도 최적화
    std::cin.tie(NULL);                // 입출력 묶음 해제
    std::cout.tie(NULL);                // 입출력 묶음 해제

    int N;
    std::cin>>N;
    
    std::vector<std::vector<int>> map(N, std::vector<int>(N, 0));
    for(int i = 0; i < N; ++i)
    {
        std::string input;
        std::cin >> input;
 
        for (int j = 0; j < N; j++) 
        {
            map[i][j] = input.at(j) - '0';
        }
    }
    
    std::vector<int> result;
    
    for(int y = 0; y < N; ++y)
    {
        for(int x = 0; x < N; ++x)
        {
            int cnt = 0;
            if (map[y][x] != 1)        
            {
                continue;
            }
            cnt++;
            std::stack<std::pair<int, int>> st;
            map[y][x] = 2;
            st.push({y, x});
            while(!st.empty())
            {
                auto curPos = st.top();
                st.pop();
                
                for (auto& nextPos : dir)
                {
                    int nextY = curPos.first + nextPos.first;
                    int nextX = curPos.second + nextPos.second;
                    
                    if (nextY < 0 || nextY >= N || nextX < 0 || nextX >= N || map[nextY][nextX] != 1)
                    {
                        continue;
                    }
                    cnt++;
                    map[nextY][nextX] = 2;
                    st.push({nextY, nextX});
                }
            }
            result.push_back(cnt);
        }
    }
    std::sort(result.begin(), result.end());
    std::cout<<result.size()<<"\n";
    for(auto value : result)
    {
        std::cout<<value<<"\n";
    }
    return 0;
}
#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<pair<int, int>> dir = 
{/*상*/{-1, 0},/*하*/{1, 0},/*좌*/{0, -1},/*우*/{0, 1}};
int main()
{
    int T;
    std::cin>>T;
    
    //가로, 세로, 배추가 심어져 있는 위치의 개수
    
    for (int i = 0; i < T; ++i)
    {
        int M, N, K;
        std::cin>>M>>N>>K;
    
        vector<vector<int>> map(N, vector<int>(M, 0));
    
        for(int i = 0; i < K; ++i)
        {
            int X, Y;
            std::cin>>X>>Y;
            map[Y][X] = 1;
        }
        
        int count = 0;  
        for (int y = 0; y < N; ++y)
        {
            for (int x = 0; x < M; ++x)
            {
                if (map[y][x] != 1)
                {
                    continue;
                }
                
                stack<pair<int, int>> st;
                ++count;
                st.push({y, x});
                map[y][x] = 0;
                
                while(!st.empty())
                {
                    auto pair = st.top();
                    st.pop();
                    int currentY = pair.first;
                    int currentX = pair.second;
                    
                    for(auto& pair : dir)
                    {
                        int nextY = pair.first + currentY;
                        int nextX = pair.second + currentX;
                    
                        if (nextY < 0 || map.size() <= nextY || nextX < 0 || map[0].size() <= nextX)
                        {
                            continue;
                        }
                    
                        if (map[nextY][nextX] == 0)
                        {
                            continue;
                        }
                        map[nextY][nextX] = 0;
                        st.push({nextY, nextX});
                    }
                }
            }
        }
        std::cout<<count<<std::endl;
    }
}
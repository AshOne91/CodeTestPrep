#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

int main()
{
    std::ios::sync_with_stdio(false);  // 입출력 속도 최적화
    std::cin.tie(NULL);                // 입출력 묶음 해제
    std::cout.tie(NULL);                // 입출력 묶음 해제

    int testCase;
    std::cin>>testCase;
    for(int i = 0; i < testCase; ++i)
    {
        std::queue<std::pair<int, int>> qu;
        std::vector<int> sortedList;
        int N, M;
        std::cin>>N>>M;
        for(int i = 0; i < N; ++i)
        {
            int value;
            std::cin>>value;
            qu.push({i, value});
            sortedList.push_back(value);
        }
        
        std::sort(sortedList.begin(), sortedList.end(), [](auto lhs, auto rhs){
            return lhs > rhs;
        });
        
        int cnt = 0;
        int index = 0;
        while(!qu.empty())
        {
            auto value = qu.front();
            // 정렬이 되었다는 뜻
            if (value.second == sortedList[index])
            {
                cnt++;
                index++;
                qu.pop();
                // 찾던 인덱스다.
                if (value.first == M)
                {
                    break;
                }
            }
            else//뒤로 보낸다.
            {
                qu.pop();
                qu.push(value);
            }
        }
        std::cout<<cnt<<"\n";
    }
    return 0;
}
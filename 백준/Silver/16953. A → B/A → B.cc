#include<iostream>
#include<climits>
#include<queue>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    
    int A, B;
    std::cin>>A>>B;
    std::queue<std::pair<int/*cnt*/, long long/*value*/>> qu;
    qu.push({1, A});
    
    int result = -1;
    while(!qu.empty())
    {
        auto value = qu.front();
        qu.pop();
        
        if (value.second > B)
        {
            continue;
        }
        if (value.second == B)
        {
            result = value.first;
            break;
        }
        
        qu.push({value.first + 1, value.second * 2});
        long long newValue = (value.second * 10) + 1;
        qu.push({value.first + 1, newValue});
    }
    
    std::cout<<result;
    return 0;
}
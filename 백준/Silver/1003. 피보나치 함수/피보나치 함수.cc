#include<iostream>
#include<vector>

std::vector<std::pair<int, int>> dpMap(41);

void countFibo(int n)
{
    for(int i = 2; i <= n; ++i)
    {
        dpMap[i] = std::make_pair((dpMap[i-1].first + dpMap[i-2].first),
                                  (dpMap[i-1].second + dpMap[i-2].second));
    }
}

int main()
{
    int T;
    std::cin>>T;
    dpMap[0] = std::make_pair(1, 0);
    dpMap[1] = std::make_pair(0, 1);
    
    for(int i = 0; i < T; ++i)
    {
        int N;
        std::cin>>N;
        countFibo(N);
        std::cout<<dpMap[N].first <<' '<<dpMap[N].second<<"\n";
    }
    return 0;
}
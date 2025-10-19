#include <iostream>
#include <algorithm>
#include <string>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int N;
    std::cin>>N;
    std::vector<std::string> results(N);
    for (int i = 0; i < N; ++i)
    {
        std::cin>>results[i];
    }

    std::sort(results.begin(), results.end(), [](auto& lhs, auto& rhs){
        if (lhs.size() == rhs.size())
        {
            return lhs < rhs;
        }
        return lhs.size() < rhs.size();
    });

    results.erase(std::unique(results.begin(), results.end()), results.end());
    
    for(auto& str : results)
    {
        std::cout<<str<<std::endl;
    }
    return 0;
}
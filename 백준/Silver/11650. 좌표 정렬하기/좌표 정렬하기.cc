#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin>>N;
    std::vector<std::pair<int, int>> pos(N);
    for (int i = 0; i < N; ++i)
    {
        std::cin>>pos[i].first>>pos[i].second;
    }

    std::stable_sort(pos.begin(), pos.end(), [](const auto& lhs, const auto& rhs){
        if (lhs.first != rhs.first)
        {
            return lhs.first < rhs.first;
        }
        return lhs.second < rhs.second;
    });

    for(const auto& result : pos)
    {
        std::cout<<result.first<<' '<<result.second<<'\n';
    }
    return 0;
}
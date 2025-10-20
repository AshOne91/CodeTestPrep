#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int N;
    std::cin>>N;
    std::vector<std::pair<int, std::string>> results;
    for (int i = 0; i < N; ++i)
    {
        int age;
        std::string name;
        std::cin>>age>>name;
        results.push_back({age, name});
    }

    std::stable_sort(results.begin(), results.end(), [](const auto& lhs, const auto& rhs){
        return lhs.first < rhs.first;
    });

    for (const auto& result : results)
    {
        std::cout<<result.first<<' '<<result.second<<'\n';
    }
    return 0;
}

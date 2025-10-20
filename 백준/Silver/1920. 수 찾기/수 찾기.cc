#include <iostream>
#include <unordered_set>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int N;
    std::cin>>N;
    std::unordered_set<int> numbers;
    for (int i = 0; i < N; ++i)
    {
        int num;
        std::cin>>num;
        numbers.insert(num);
    }
    int M;
    std::cin>>M;
    for (int i = 0; i < M; ++i)
    {
        int num;
        std::cin>>num;
        std::cout<<(numbers.find(num) != numbers.end() ? 1 : 0)<<'\n';
    }
}
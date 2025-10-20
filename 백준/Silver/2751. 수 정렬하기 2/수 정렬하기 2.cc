#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N;
    std::cin>>N;

    std::vector<int> sortedList(N);
    for (int i = 0; i < N; ++i)
    {
        std::cin>>sortedList[i];
    }

    std::sort(sortedList.begin(), sortedList.end());

    for (int i = 0; i < N; ++i)
    {
        std::cout<<sortedList[i]<<'\n';
    }
    return 0;
}
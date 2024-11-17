#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int N;
    std::cin >> N;

    std::vector<int> lis; // LIS를 저장하는 배열
    for (int i = 0; i < N; ++i)
    {
        int x;
        std::cin >> x;
        auto it = std::lower_bound(lis.begin(), lis.end(), x);
        if (it == lis.end())
            lis.push_back(x);
        else
            *it = x;
    }

    std::cout << lis.size();
}

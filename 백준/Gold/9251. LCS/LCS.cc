#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::string str_1, str_2;
    std::cin >> str_1 >> str_2;

    // 항상 str_1이 더 짧게
    if (str_1.size() > str_2.size()) std::swap(str_1, str_2);

    int n = str_1.size();
    int m = str_2.size();
    
    std::vector<int> prev(m + 1, 0), curr(m + 1, 0);

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (str_1[i - 1] == str_2[j - 1])
                curr[j] = prev[j - 1] + 1;
            else
                curr[j] = std::max(prev[j], curr[j - 1]);
        }
        std::swap(prev, curr);
    }

    std::cout << prev[m];
}

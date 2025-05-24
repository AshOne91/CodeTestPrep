#include <iostream>
#include <string>
#include <vector>
#include <stack>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::string str_1, str_2;
    std::cin >> str_1 >> str_2;

    std::string temp = "0";
    str_1 = temp + str_1;
    str_2 = temp + str_2;

    int x_size = (int)str_1.length();
    int y_size = (int)str_2.length();

    std::vector<std::vector<int>> dp(y_size, std::vector<int>(x_size, 0));

    for (int y = 1; y < y_size; ++y)
    {
        for (int x = 1; x < x_size; ++x)
        {
            if (str_1[x] == str_2[y])
            {
                dp[y][x] = dp[y - 1][x - 1] + 1;
            }
            else
            {
                dp[y][x] = std::max(dp[y - 1][x], dp[y][x - 1]);
            }
        }
    }

    int result = dp[y_size - 1][x_size - 1];
    std::cout << result << "\n";

    // 공통 부분 수열 추적 (역추적)
    int y_index = y_size - 1;
    int x_index = x_size - 1;
    std::stack<char> st;

    while (y_index > 0 && x_index > 0)
    {
        if (str_1[x_index] == str_2[y_index])
        {
            st.push(str_1[x_index]);
            --x_index;
            --y_index;
        }
        else if (dp[y_index - 1][x_index] > dp[y_index][x_index - 1])
        {
            --y_index;
        }
        else
        {
            --x_index;
        }
    }

    // 공통 부분 수열 출력
    while (!st.empty())
    {
        std::cout << st.top();
        st.pop();
    }
    std::cout << "\n";

    return 0;
}
#include <iostream>
#include <queue>
#include <unordered_map>
#include <string>
#include <vector>

int main()
{
    std::ios::sync_with_stdio(false);  // 입출력 속도 최적화
    std::cin.tie(NULL);                // 입출력 묶음 해제
    std::cout.tie(NULL);               // 입출력 묶음 해제

    int T;
    std::cin >> T;
    auto cmp = [](int left, int right) { return left > right; };

    for (int i = 0; i < T; ++i)
    {
        std::priority_queue<int, std::vector<int>, decltype(cmp)> minQu(cmp);
        std::priority_queue<int> maxQu;
        std::unordered_map<int, int> deleteCount;

        int Q;
        std::cin >> Q;
        for (int j = 0; j < Q; ++j)
        {
            std::string cmd;
            std::cin >> cmd;
            int value;
            std::cin >> value;

            if (cmd == "I")
            {
                minQu.push(value);
                maxQu.push(value);
                deleteCount[value]++;
            }
            else if (cmd == "D")
            {
                if (value == 1)
                {
                    while (!maxQu.empty() && deleteCount[maxQu.top()] == 0) maxQu.pop();
                    if (!maxQu.empty())
                    {
                        int maxVal = maxQu.top();
                        maxQu.pop();
                        deleteCount[maxVal]--;
                    }
                }
                else if (value == -1)
                {
                    while (!minQu.empty() && deleteCount[minQu.top()] == 0) minQu.pop();
                    if (!minQu.empty())
                    {
                        int minVal = minQu.top();
                        minQu.pop();
                        deleteCount[minVal]--;
                    }
                }
            }
        }

        // 최대값과 최소값 갱신 후 출력
        while (!maxQu.empty() && deleteCount[maxQu.top()] == 0) maxQu.pop();
        while (!minQu.empty() && deleteCount[minQu.top()] == 0) minQu.pop();

        if (maxQu.empty() || minQu.empty())
        {
            std::cout << "EMPTY\n";
        }
        else
        {
            std::cout << maxQu.top() << " " << minQu.top() << "\n";
        }
    }

    return 0;
}

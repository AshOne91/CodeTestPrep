#include<iostream>
#include<algorithm>
#include<vector>

int main()
{
    int n = 0;
    std::vector<int> times;
    
    std::cin >> n;
    for(int i = 0; i < n; ++i)
    {
        int time = 0;
        std::cin >> time;
        times.push_back(time);
    }
    
    std::sort(times.begin(), times.end());
    int totalTime = 0;
    int answer = 0;
    for(int i = 0; i < times.size(); ++i)
    {
        totalTime = times[i] + totalTime;
        answer += totalTime;
    }
    
    std::cout << answer;
    return 0;
}
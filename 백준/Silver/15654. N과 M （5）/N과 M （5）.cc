#include <iostream>
#include <vector>
#include <algorithm>


int N, M;
std::vector<bool> visited(10001, false);
void back_traking(std::vector<int>& nums
, std::vector<int>& results)
{
    if (static_cast<int>(results.size()) == M)
    {
        for (auto value : results)
        {
            std::cout<<value<<' ';
        }
        std::cout<<'\n';
        return;
    }
    
    if (static_cast<int>(results.size()) > M)
    {
        return;
    }
    
    for (int i = 0; i < static_cast<int>(nums.size()); ++i)
    {
        if (visited[nums[i]] == true)
            continue;
        visited[nums[i]] = true;
        results.push_back(nums[i]);
        back_traking(nums, results);
        results.pop_back();
        visited[nums[i]] = false;
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    
    std::cin>>N>>M;
    std::vector<int> nums(N);
    for (int i = 0; i < N; ++i)
    {
        std::cin>>nums[i];
    }
    
    std::sort(nums.begin(), nums.end());
    
    std::vector<int> results;
    back_traking(nums, results);
}
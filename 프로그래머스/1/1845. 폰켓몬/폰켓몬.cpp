#include <vector>
#include <unordered_set>
using namespace std;

int solution(vector<int> nums)
{
    unordered_set<int> poket;
    for(auto num : nums)
    {
        poket.insert(num);
    }
    
    int answer = std::min(nums.size()/2, poket.size());
    return answer;
}
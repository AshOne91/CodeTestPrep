#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int combine(int a, int b)
{
    int ret = a;
    while(b > 0)
    {
        ret *= 10;
        b /= 10;
    }
    return ret + b;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector <string> strings;
    for (auto num : numbers)
    {
        strings.push_back(to_string(num));
    }
    std::sort(strings.begin(), strings.end(),[](const string& lhs, const string& rhs)
              {
                 return (lhs+rhs) > (rhs+lhs);
              });
    for(auto& value : strings)
    {
        answer += value;
    }
    
    return answer[0] == '0' ? "0" : answer;
}
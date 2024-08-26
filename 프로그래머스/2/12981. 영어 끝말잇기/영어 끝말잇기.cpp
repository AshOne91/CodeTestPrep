#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    unordered_set<string> wordMap;
    for(int i = 0; i < words.size(); ++i)
    {
        if (wordMap.find(words[i]) == wordMap.end())
        {
            wordMap.insert(words[i]);
        }
        else
        {  
            answer.push_back((i % n) + 1);
            answer.push_back((i / n) + 1);
            break;
        }
        
        if ((i - 1) >= 0)
        {
            if (words[i-1].back() != words[i].front())
            {
                answer.push_back((i % n) + 1);
                answer.push_back((i / n) + 1);
                break;
            }
        }
    }

    if (answer.size() == 0)
    {
        answer.assign(2, 0);
    }
    return answer;
}
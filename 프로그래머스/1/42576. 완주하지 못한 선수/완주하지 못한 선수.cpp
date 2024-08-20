#include <string>
#include <vector>
#include <unordered_map>

using namespace std;
unordered_map<string, int> participant_map;

string solution(vector<string> participant, vector<string> completion) {
    for(auto& name: participant)
    {
        ++participant_map[name];
    }
    
    for(auto& name: completion)
    {
        --participant_map[name];
        if(participant_map[name] == 0)
        {
            participant_map.erase(name);
        }
    }    
    
    return participant_map.begin()->first;
}
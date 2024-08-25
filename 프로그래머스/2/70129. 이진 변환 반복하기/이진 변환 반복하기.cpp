#include <string>
#include <vector>
#include <algorithm>
#include <bitset>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    int zeroCount = 0;
    int checkCount = 0;
    while(s!="1")
    {
        ++checkCount;
        // 0갯수
        zeroCount += count(s.begin(), s.end(), '0');
        
        // 1갯수
        int bitStr = count(s.begin(), s.end(), '1');
        s = bitset<32>(bitStr).to_string();
        s = s.substr(s.find('1'));
    }
    
    return {checkCount, zeroCount};
}
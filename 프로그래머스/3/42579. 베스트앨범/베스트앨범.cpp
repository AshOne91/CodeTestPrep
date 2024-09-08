#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    unordered_map</*장르*/string, /*횟수*/int> genresCount;
    unordered_map</*장르*/string, vector<pair</*index*/int, int>>> genresMap;
    for(int i = 0; i < genres.size(); ++i)
    {
        genresCount[genres[i]] += plays[i];
        genresMap[genres[i]].push_back({i, plays[i]});
    }
    
    vector<pair<string, int>> sortedGenresCount(genresCount.begin(), genresCount.end());
    sort(sortedGenresCount.begin(), sortedGenresCount.end(), [](pair<string, int>& lhs, pair<string, int>& rhs)
         {
             return lhs.second > rhs.second;
         });
    
    for(auto& genre : sortedGenresCount)
    {
        sort(genresMap[genre.first].begin(), genresMap[genre.first].end(), [](pair<int, int>& lhs, pair<int, int>& rhs)
             {
                 if (lhs.second == rhs.second)
                 {
                     return lhs.first < rhs.first;
                 }
                 return lhs.second > rhs.second;
             });
        
        for(int i = 0; i < genresMap[genre.first].size(); ++i)
        {
            if ( i > 1)
            {
                break;
            }
            answer.push_back(genresMap[genre.first][i].first);
        }
    }
    
    return answer;
}
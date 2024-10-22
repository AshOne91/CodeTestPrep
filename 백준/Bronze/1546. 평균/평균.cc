#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>

int main()
{
    int N;
    std::cin>>N;
    
    std::vector<float> totalScore;
    for(int i = 0; i < N; ++i)
    {
        float score = 0;
        std::cin>>score;
        totalScore.push_back(score);
    }
    
    float M = *std::max_element(totalScore.begin(), totalScore.end());
    for(int i = 0; i < totalScore.size(); ++i)
    {
        totalScore[i] = totalScore[i] / M * 100.0f;
    }
    
    float sum = std::accumulate(totalScore.begin(), totalScore.end(), 0.0f);
    float avg = sum / totalScore.size();
    std::cout<<avg<<std::endl;
    return 0;
}
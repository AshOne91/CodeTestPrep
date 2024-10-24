#include<iostream>
#include<vector>
#include<unordered_map>
#include<limits>
#include<cmath>
#include<algorithm>

int main()
{
    int N;
    std::cin>>N;
    
    //1. 산술평균
    double total = 0.0;
    //2. 중앙값
    std::vector<int> values;
    //3. 최빈값->여러 개 있을 때에는 최빈값 중 두 번째 값
    std::unordered_map<int, int> cntMap;
    //4. 최대값 최소값 범위 출력
    int minValue = std::numeric_limits<int>::max();
    int maxValue = std::numeric_limits<int>::min();
    for(int i = 0; i < N; ++i)
    {
        int num;
        std::cin>>num;
        //1.산술평균
        total += num;
        //2.중앙값
        values.push_back(num);
        //3. 최반값
        cntMap[num]++;
        //4. 최대값 최소값
        minValue = std::min(minValue, num);
        maxValue = std::max(maxValue, num);
    }
    
    //1
    std::cout<<std::round(total/N) + 0.0 <<std::endl;
    //2
    std::sort(values.begin(), values.end());
    std::cout<<values[N/2]<<std::endl;
    //3
    std::vector<std::pair<int, int>> cnts(cntMap.begin(), cntMap.end());
    std::sort(cnts.begin(), cnts.end(), [](auto& lhs, auto& rhs){
        if (lhs.second == rhs.second)
        {
            return lhs.first < rhs.first;
        }
        return lhs.second > rhs.second;
    });
    if (cnts.size() > 2)
    {
        //두 카운트 값이 같은경우
        if (cnts[0].second == cnts[1].second)
        {
            std::cout<<cnts[1].first<<std::endl;
        }
        else
        {
            std::cout<<cnts[0].first<<std::endl;
        }
        
    }else
    {
        std::cout<<cnts[0].first<<std::endl;
    }
    std::cout<<maxValue - minValue<<std::endl;
    return 0;
}

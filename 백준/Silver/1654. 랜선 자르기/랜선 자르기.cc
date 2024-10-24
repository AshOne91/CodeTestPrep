#include<iostream>
#include<limits>
#include<vector>

int main()
{
    int K, N;
    std::cin>>K>>N;
    
    std::vector<int> cableList;
    long long maxValue = std::numeric_limits<long long>::min();
    for (int i = 0; i < K; ++i)
    {
        long long num;
        std::cin>>num;
        cableList.push_back(num);
        maxValue = std::max(maxValue, num);
    }
    
    long long left = 1;
    long long right = maxValue;
    long long mid = -1;
    long long retvalue = 0;
    while (left <= right)
    {
        mid = (left + right) / 2;
        
        long long sum = 0;
        
        for (int i = 0; i < cableList.size(); ++i)
        {
            sum += cableList[i]/mid;
        }
        
        if (sum >= N)
        {
            left = mid + 1;
            
            retvalue = std::max(retvalue, mid);
        }
        else
        {
            right = mid - 1;
        }
    }
    std::cout<<retvalue<<std::endl;
    return 0;
}
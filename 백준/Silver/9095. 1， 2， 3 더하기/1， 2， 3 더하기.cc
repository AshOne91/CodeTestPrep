#include<iostream>
#include<vector>
std::vector<int> dpMap(12, 0);

int main()
{
    int T;
    std::cin>>T;

    dpMap[1] = 1;
    dpMap[2] = 2;
    dpMap[3] = 4;
    
    for(int i = 4; i < 11; ++i)
    {
        dpMap[i] = dpMap[i - 1] + dpMap[i - 2] + dpMap[i - 3];
    }
    
    for (int i = 0; i < T; ++i)
    {
        int n;
        std::cin>>n;
        std::cout<<dpMap[n]<<std::endl;
    }
    return 0;
}
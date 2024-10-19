#include<iostream>
#include<vector>

int main()
{
    int T;
    std::cin>>T;
    
    std::vector<int> result;
    for(int i = 0; i < T; ++i)
    {
        int H, W, N;
        std::cin>>H>>W>>N;
        
        int floor = N % H;
        int room = N / H + 1;
        
        if (floor == 0)
        {
            floor = H;
            room = N / H;
        }
        int num = floor * 100 + room;
        result.push_back(num);
    }
    
    for(auto value : result)
    {
        std::cout<<value<<std::endl;
    }
    
    return 0;
}
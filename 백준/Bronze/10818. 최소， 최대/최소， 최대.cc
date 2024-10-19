#include<iostream>
#include<limits>

int main()
{
    int N;
    std::cin>>N;
    
    int max = std::numeric_limits<int>::min();
    int min = std::numeric_limits<int>::max();
    for(int i = 0; i < N; ++i)
    {
        int num;
        std::cin>>num;
        
        max = std::max(max, num);
        min = std::min(min, num);
    }
    std::cout<<min<<" "<<max<<std::endl;
    return 0;
}
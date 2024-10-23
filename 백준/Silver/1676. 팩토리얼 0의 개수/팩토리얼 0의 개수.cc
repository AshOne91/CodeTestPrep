#include<iostream>

int main()
{
    int N = 0;
    int cnt = 0;
    
    std::cin>>N;
    
    for(int i = 5; i <= N; i *= 5)
    {
        cnt += (N/i);
    }
    
    std::cout<<cnt;
    
    return 0;
}
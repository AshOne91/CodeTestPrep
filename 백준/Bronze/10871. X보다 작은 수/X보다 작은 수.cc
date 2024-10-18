#include<iostream>

int main()
{
    int N, X;
    std::cin>>N>>X;
    
    for(int i = 0; i < N; ++i)
    {
        int num;
        std::cin>>num;
        
        if (num < X)
        {
            std::cout<<num<<" ";
        }
    }

    return 0;
}
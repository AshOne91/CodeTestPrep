#include<iostream>
#include<string>

int main()
{
    int N;
    std::cin>>N;
    
    std::string num;
    std::cin>>num;
    
    int sum = 0;
    for(int i = 0; i < N; ++i)
    {
        sum += (num[i] - '0');
    }
    std::cout<<sum<<std::endl;
    return 0;
}
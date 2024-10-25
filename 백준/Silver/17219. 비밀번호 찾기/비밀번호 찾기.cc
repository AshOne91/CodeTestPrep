#include<iostream>
#include<unordered_map>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    
    int N, M;
    std::cin>>N>>M;
    
    std::unordered_map<std::string, std::string> passwordByAddress;
    for (int i = 0; i < N; ++i)
    {
        std::string address;
        std::string password;
        std::cin>>address>>password;
        passwordByAddress[address] = password;
    }
    for (int i = 0; i < M; ++i)
    {
        std::string address;
        std::cin>>address;
        std::cout<<passwordByAddress[address]<<"\n";
    }
    return 0;
}
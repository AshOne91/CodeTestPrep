#include<iostream>
#include<string>
#include<vector>

int main()
{
    int A,B,C;
    std::cin>>A>>B>>C;
    
    std::string str = std::to_string(A*B*C);
    
    std::vector<int> result(10, 0);
    for(auto ch : str)
    {
        result[ch - '0']++;
    }
    for(auto count : result)
    {
        std::cout<<count<<std::endl;
    }
    return 0;
}
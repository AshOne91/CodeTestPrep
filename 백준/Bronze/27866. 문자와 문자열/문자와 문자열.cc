#include<iostream>
#include<string>

int main()
{
    std::string str;
    std::cin>>str;
    int i;
    std::cin>>i;
    
    std::cout<<str[i-1]<<std::endl;
    return 0;
}
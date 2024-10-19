#include<iostream>

int main()
{
    int A,B,C;
    std::cin>>A>>B>>C;
    
    //숫자로 생각
    std::cout<<A+B-C<<std::endl;
    
    //문자열로 생각
    std::string str = std::to_string(A) + std::to_string(B);
    int num = std::stoi(str);
    std::cout<<num-C<<std::endl;
    return 0;
}
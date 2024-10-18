#include<iostream>

int main()
{
    int A,B;
    std::cin>>A;
    std::cin>>B;
    
    std::cout.precision(12);
    std::cout<<((double)A/(double)B)<<std::endl;
    return 0;
}
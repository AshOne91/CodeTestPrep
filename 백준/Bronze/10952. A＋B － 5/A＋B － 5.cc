#include<iostream>

int main()
{
    int A,B;
    
    while(std::cin>>A>>B)
    {
        if (A == 0)
            break;
        
        std::cout<<A+B<<std::endl;
    }
    return 0;
}
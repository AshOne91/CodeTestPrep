#include<iostream>

int main()
{
    int H,M;
    std::cin>>H>>M;
    
    M -= 45;
    if (M < 0)
    {
        H -= 1;
        if (H < 0)
        {
            H = 23;
        }
        
        M = 60 + M;
    }
    std::cout<<H<<" "<<M<<std::endl;
    
    return 0;
}
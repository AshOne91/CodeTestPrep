#include<iostream>
#include<string>

int main()
{
    int N;
    std::cin>>N;
    for(int i = 1; i < N; ++i)
    {
        int num = i;
        int check = i;
        while(true)
        {
            if (check == 0)
            {
                break;
            }
            num += check % 10;
            check /= 10;
        }
        if (num == N)
        {
            std::cout<<i<<std::endl;
            return 0;
        }
    }
    std::cout<<0<<std::endl;
    return 0; 
}
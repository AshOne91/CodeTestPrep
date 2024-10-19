#include<iostream>

int main()
{
    int max = 0;
    int index = 0;
    for(int i = 1; i <= 9; ++i)
    {
        int num;
        std::cin>>num;
        max = std::max(num, max);
        if(max == num)
        {
            index = i;
        }
    }
    std::cout<<max<<std::endl;
    std::cout<<index<<std::endl;
    return 0;
}
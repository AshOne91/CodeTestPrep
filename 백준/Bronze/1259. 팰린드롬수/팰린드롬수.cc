#include<iostream>
#include<algorithm>
#include<string>

int main()
{
    while(true)
    {
        std::string num;
        std::cin>>num;
        if (num == "0")
        {
            return 0;
        }
        std::string reverseNum = num;
        std::reverse(reverseNum.begin(), reverseNum.end());
        if (num == reverseNum)
        {
            std::cout<<"yes"<<std::endl;
        }
        else
        {
            std::cout<<"no"<<std::endl;
        }
    } 
    return 0;
}
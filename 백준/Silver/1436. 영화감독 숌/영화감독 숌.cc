#include<iostream>
#include<string>

int main()
{
    int N;
    std::cin>>N;
    
    int rtv = 0;
    for(int i = 1;;++i)
    {
        if(N == 0)
        {
            break;
        }
        std::string check = std::to_string(i);
        if (check.find("666") != std::string::npos)
        {
            rtv = i;
            N--;
        }
    }
    
    std::cout<<rtv<<std::endl;
    return 0;
}
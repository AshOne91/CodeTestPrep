#include<iostream>
#include<string>

int main()
{
    int T;
    std::cin>>T;
    
    for(int i = 0; i < T; ++i)
    {
        int R;
        std::cin>>R;
        std::string str;
        std::cin>>str;
        
        for(auto ch : str)
        {
            for(int j = 0; j < R; ++j)
            {
                std::cout<<ch;
            }
        }
        
        std::cout<<std::endl;
    }
    
    return 0;
}
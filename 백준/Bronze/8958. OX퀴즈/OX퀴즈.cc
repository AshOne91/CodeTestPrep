#include<iostream>
#include<string>

int main()
{
    int n;
    std::cin>>n;
    
    for(int i = 0; i < n; ++i)
    {
        std::string str;
        std::cin>>str;
        
        int score = 0;
        int oCount = 0;
        for(auto ch : str)
        {
            if (ch == 'O')
            {
                oCount += 1;
                score += oCount;
            }
            else
            {
                oCount = 0;
            }
        }
        std::cout<<score<<std::endl;
    }
    
    return 0;
}
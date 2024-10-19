#include<iostream>
#include<string>

int main()
{
    std::string str;
    //std::cin>>str;
    std::getline(std::cin, str);
    
    int count = 0;
    bool flag = true;
    for(auto ch : str)
    {
        if (ch != ' ')
        {
            if(flag == true)
            {
                flag = false;
                ++count;
            }
        }
        else
        {
            flag = true;
        }
    }
    std::cout<<count<<std::endl;
    return 0;
}
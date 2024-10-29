#include<iostream>
#include<string>

int main()
{
    std::string str;
    std::cin>>str;
    
    int result = 0;
    std::string num;
    bool isMinus = false;
    for (int i = 0; i <= (int)str.size(); ++i)
    {
        if (str[i] == '-' || str[i] == '+' ||  i == (int)str.size())
        {
            if (isMinus == true)
            {
                result -= std::stoi(num);
                num = "";
            }
            else
            {
                result += stoi(num);
                num = "";
            }
        }
        else
        {
            num += str[i];
        }
        
        if (str[i] == '-')
        {
            isMinus = true;
        }
    }
    std::cout<<result;
}
#include<iostream>
#include<unordered_map>
#include<vector>

int main()
{
    int testCase;
    std::cin>>testCase;
    
    for (int i = 0; i < testCase; ++i)
    {
        int count;
        std::cin>>count;
        std::unordered_map<std::string, int> wearMap;
        for(int j = 0; j < count; ++j)
        {
            std::string name, tag;
            std::cin>>name>>tag;
            wearMap[tag]++;
        }
        
        int rtv = 1;
        for(auto& value : wearMap)
        {
            rtv *= (value.second + 1);
        }
        rtv -= 1;
        std::cout<<rtv<<"\n";
    }
    return 0;
}
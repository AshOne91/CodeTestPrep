#include<iostream>
#include<unordered_set>

int main()
{
    std::unordered_set<int> check;
    for(int i = 0; i < 10; ++i)
    {
        int num;
        std::cin>>num;
        
        check.insert(num%42);
    }
    
    std::cout<<check.size()<<std::endl;
}
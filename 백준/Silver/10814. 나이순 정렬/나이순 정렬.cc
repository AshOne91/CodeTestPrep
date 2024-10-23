#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

int main()
{
    int N;
    std::cin>>N;
    
    std::vector<std::pair<int, std::string>> sortedList;
    for(int i = 0; i < N; ++i)
    {
        int age;
        std::string name;
        std::cin>>age>>name;
        sortedList.push_back({age, name});
    }
    
    std::stable_sort(sortedList.begin(), sortedList.end(), [](auto& lhs, auto& rhs){
        return lhs.first < rhs.first;
    });
    
    for(const auto& [age, name] : sortedList)
    {
        std::cout<<age<<" "<<name<<std::endl;
    }
    return 0;
}
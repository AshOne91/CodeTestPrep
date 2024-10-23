#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

int main()
{
    std::vector<std::string> words;
    int N;
    std::cin>>N;
    for(int i = 0; i < N; ++i)
    {
        std::string word;
        std::cin>>word;
        words.push_back(word);
    }
    
    std::sort(words.begin(), words.end(), [](auto& lhs, auto& rhs){
        if (lhs.size() == rhs.size())
        {
            return lhs < rhs;
        }
        return lhs.size() < rhs.size();
    });
    words.erase(std::unique(words.begin(), words.end()), words.end());
    
    for(auto& str : words)
    {
        std::cout<<str<<std::endl;
    }
    return 0;
}
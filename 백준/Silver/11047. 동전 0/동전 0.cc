#include<iostream>
#include<vector>

int main()
{
    int N, K;
    std::cin>>N>>K;
    
    std::vector<int> coinList(N, 0);
    for (int i = 0; i < N; ++i)
    {
        std::cin>>coinList[i];
    }
    
    int coinCount = 0;
    for(int i = N; 0 < i; --i)
    {
        if ((K / coinList[i - 1]) > 0)
        {
            int count = 0;
            count += (K / coinList[i - 1]);
            K -= (count * coinList[i - 1]);
            coinCount += count;
        }
        
        if (K == 0)
        {
            break;
        }
    }
    std::cout<<coinCount<<std::endl;
    return 0;
}
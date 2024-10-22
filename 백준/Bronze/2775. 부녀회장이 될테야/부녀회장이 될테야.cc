#include<iostream>
#include<vector>

int main()
{
    // a층의 b호에 살려면 
    //자신의 아래(a-1)층의 1호 부터 b호까지 
    //사람들의 수의 합만큼 사람들을 데려와 살아야된다.
    int T;
    std::cin>>T;
    
    for(int i = 0; i < T; ++i)
    {
        //k층 n호
        int k, n;
        std::cin>>k>>n;
        
        // 0층부터 존재
        std::vector<std::vector<int>> apt(k + 1, std::vector<int>(n, 0));
        
        //0층 i호에는 i명이 삼
        for(int i = 0; i < n; ++i)
        {
            apt[0][i] = i + 1;
        }
        
        //아래(a-1)층의 1호부터 b호까지 사람들의 수의 합만큼 사람이 살아야됨
        for(int i = 1; i <= k; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                int num = 0;
                for(int k = 0; k <= j; ++k)
                {
                    num += apt[i-1][k];
                }
                apt[i][j] = num;
            }
        }
        std::cout<<apt[k][n - 1]<<std::endl;
    }
    return 0;
}
#include<iostream>
#include<vector>
#include<queue>

std::vector<int> checkResult(100001, 0);

int main()
{
    int N, K;
    std::cin>>N>>K;
    
    std::queue<int> qu;
    qu.push(N);
    checkResult[N] = 0;
    
    while (!qu.empty())
    {
        int curPos = qu.front();
        qu.pop();
        
        if (curPos == K)
        {
            break;
        }
        
        int minusPos = curPos - 1;
        int plusPos = curPos + 1;
        int multiPos = curPos * 2;
        
        if (minusPos >= 0 && checkResult[minusPos] == 0)
        {
            qu.push(minusPos);
            checkResult[minusPos] = checkResult[curPos] + 1;
        }
        
        if (plusPos < 100001 && checkResult[plusPos] == 0)
        {
            qu.push(plusPos);
            checkResult[plusPos] = checkResult[curPos] + 1;
        }
        
        if (multiPos < 100001 && checkResult[multiPos] == 0)
        {
            qu.push(multiPos);
            checkResult[multiPos] = checkResult[curPos] + 1;
        }
    }
    
    std::cout<<checkResult[K];
}


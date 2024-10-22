#include<iostream>

int main()
{
    int N;
    std::cin>>N;
    
    int num = 1;
    int loopCnt = 0;
    for(;;)
    {
        if ((N - num) <= 0)
        {
            std::cout<<loopCnt + 1<<std::endl;
            return 0;
        }
        loopCnt++;
        num += loopCnt * 6;
    }
    return 0;
}
#include<iostream>
#include<vector>
#include<algorithm>

int main()
{
    std::ios::sync_with_stdio(false);  // 입출력 속도 최적화
    std::cin.tie(NULL);                // 입출력 묶음 해제
    
    int N;
    std::cin>>N;
    
    std::vector<int> sortedList;
    for(int i = 0; i < N; ++i)
    {
        int num;
        std::cin>>num;
        sortedList.push_back(num);
    }
    
    std::sort(sortedList.begin(), sortedList.end());
    
    for(int i = 0; i < N; ++i)
    {
        std::cout << sortedList[i] << '\n';  // std::endl 대신 '\n' 사용으로 출력 성능 개선
    }
    return 0;
}

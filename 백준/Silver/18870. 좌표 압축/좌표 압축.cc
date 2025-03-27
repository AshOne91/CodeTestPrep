//❓좌표 압축이란
// 수의 범위가 매우 큰 상태에서 수의 값과 
// 상관 없이 숫자 간의 대소관계만 알면 될 때 이용하는 알고리즘이다.

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

// 아니 좌표압축이 뭐인지 알려줘야 될거 아니야
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    
    int N;
    std::cin>>N;
    std::vector<int> value(N);
    std::vector<int> pos(N);
    for (int i = 0; i < N; ++i)
    {
        int num;
        std::cin>>num;
        value[i] = num;
        pos[i] = num;
    }
    
    std::sort(value.begin(), value.end());/*오름차순*/
    value.erase(std::unique(value.begin(), value.end()), value.end());
    
    std::vector<int> result;
    for (int p : pos)
    {
        auto it = std::lower_bound(value.begin(), value.end(), p);
        std::cout<<it - value.begin()<<' ';
    } 
}
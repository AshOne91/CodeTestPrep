#include <iostream>
#include <vector>
#include <algorithm>  

// 답지봄
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N, M;
    std::cin >> N >> M;

    std::vector<int> tree(N);
    int low = 0, high = 0;

    for (int i = 0; i < N; ++i)
    {
        std::cin >> tree[i];
        high = std::max(high, tree[i]);
    }

    int result = 0;  

    while (low <= high) 
    {
        int mid = (low + high) / 2;
        long long total = 0; 

        for (int i = 0; i < N; ++i)
        {
            if (tree[i] > mid)
            {
                total += (tree[i] - mid);
            }
        }

        if (total >= M)
        {
            result = mid;   
            low = mid + 1; 
        }
        else 
        {
            high = mid - 1;  
        }
    }

    std::cout << result;
}

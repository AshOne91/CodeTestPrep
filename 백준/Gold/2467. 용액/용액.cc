#include <iostream>
#include <vector>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    
    int N;
    std::cin>>N;
    std::vector<int> arr(N);
    for (int i = 0; i < N; ++i)
    {
        std::cin>>arr[i];
    }
    
    int left = 0;
    int right = N - 1;
    int res_left = arr[left];
    int res_right = arr[right];
    int res = std::abs(res_left + res_right);
    while(left < right)
    {
        int temp = std::abs(arr[left] + arr[right]);
        if (temp < res)
        {
            res_left = arr[left];
            res_right = arr[right];
            res = temp;
        }
        
        if (arr[left] + arr[right] < 0)
        {
            left++;
        }
        else
        {
            right--;
        }
    }
    
    std::cout<<res_left<<' '<<res_right<<'\n';
}
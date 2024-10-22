#include<iostream>

// 팩토리얼을 계산하는 함수
long long factorial(int n)
{
    long long result = 1;
    for (int i = 2; i <= n; ++i)
    {
        result *= i;
    }
    return result;
}

int main()
{
    int n, k;
    std::cin >> n >> k;
    
    // 이항 계수 계산
    long long binomial_coefficient = factorial(n) / (factorial(k) * factorial(n - k));
    
    std::cout << binomial_coefficient << std::endl;
    return 0;
}
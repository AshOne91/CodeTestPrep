// 문제 요약
// 피보나치 수를 구하는 문제
// 단, n이 매우 크다 (최대 1조까지 가능)
// 그래서 일반적인 재귀나 반복문으로 풀면 시간 초과
// 행렬 곱셈과 분할 정복(거듭제곱)을 이용해야 함
//F(n+1) = F(n) + F(n-1)
// [ F(n+1) ]   =   [1 1] * [F(n)]
// [  F(n)  ]       [1 0]   [F(n-1)]

// F(n+1) = 1*F(n) + 1*F(n-1) -> 윗줄
// F(n) = 1*F(n) + 0*F(n-1) = F(n) -> 아랫줄
// 행렬 곱하면 → 다음 숫자를 만드는 공식

//[ F(1) ]   =   [1 1] * [F(0)]
//[ F(0) ]       [1 0]   [F(-1)]

//[ F(2) ]   =   [1 1] * [F(1)]
//[ F(1) ]       [1 0]   [F(0)]

//[ F(3) ]   =   [1 1] * [F(2)]
//[ F(2) ]       [1 0]   [F(1)]

// 행렬을 n번 곱하면 -> 여전히 느리다 -> 분할 정복
//A^8 = (A^4) * (A^4)
//A^4 = (A^2) * (A^2)
//A^2 = (A^1) * (A^1)

// log1조->40번 계산 가능

#include <iostream>

const unsigned long long MOD = 1000000007;

struct Matrix
{
    unsigned long long m[2][2];  
};

// 행렬 곱셈 함수
Matrix multiply(Matrix a, Matrix b) {
    Matrix result;
    result.m[0][0] = (a.m[0][0]*b.m[0][0] + a.m[0][1]*b.m[1][0]) % MOD;
    result.m[0][1] = (a.m[0][0]*b.m[0][1] + a.m[0][1]*b.m[1][1]) % MOD;
    result.m[1][0] = (a.m[1][0]*b.m[0][0] + a.m[1][1]*b.m[1][0]) % MOD;
    result.m[1][1] = (a.m[1][0]*b.m[0][1] + a.m[1][1]*b.m[1][1]) % MOD;
    return result;
}

// 반복문으로 구현한 행렬 거듭제곱
Matrix power(Matrix a, unsigned long long n) {
    Matrix result = {1, 0, 0, 1};  // 단위행렬
    while (n > 0) {
        if (n % 2 == 1) {
            result = multiply(result, a);
        }
        a = multiply(a, a);
        n /= 2;
    }
    return result;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    unsigned long long n;
    std::cin >> n;
    if (n == 0) {
        std::cout << 0 << '\n';
        return 0;
    }
    
    Matrix base = {1, 1, 1, 0};
    Matrix result = power(base, n - 1);
    
    std::cout << result.m[0][0] << '\n';
    return 0;
}






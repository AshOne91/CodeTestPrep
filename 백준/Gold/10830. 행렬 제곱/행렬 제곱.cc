#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000;

using Matrix = vector<vector<int>>;

// 행렬 곱셈 함수
Matrix multiply(const Matrix& a, const Matrix& b, int n) {
    Matrix result(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                result[i][j] = (result[i][j] + a[i][k] * b[k][j]) % MOD;
            }
        }
    }
    return result;
}

// 행렬 거듭제곱 함수
Matrix matrixPower(Matrix a, long long b, int n) {
    Matrix result(n, vector<int>(n, 0));
    // 단위 행렬로 초기화
    for (int i = 0; i < n; ++i) {
        result[i][i] = 1;
    }
    while (b > 0) {
        if (b % 2 == 1) {
            result = multiply(result, a, n);
        }
        a = multiply(a, a, n);
        b /= 2;
    }
    return result;
}

int main() {
    int n;
    long long b;
    cin >> n >> b;

    Matrix a(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }

    Matrix result = matrixPower(a, b, n);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << result[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}

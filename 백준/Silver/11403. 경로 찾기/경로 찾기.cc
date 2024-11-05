#include <iostream>
using namespace std; 
int g[101][101]; 
int main() {
    std::ios::sync_with_stdio(false);  // 입출력 속도 최적화
    std::cin.tie(NULL);                // 입출력 묶음 해제
    std::cout.tie(NULL);                // 입출력 묶음 해제
	int n; cin >> n; 
	for(int i=0; i<n; i++){
		for (int j = 0; j < n; j++) {
			cin >> g[i][j]; 
		}
	}
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (g[i][k] && g[k][j]) {
					g[i][j] = 1; 
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << g[i][j] << " ";
		}cout << "\n";
	}

}
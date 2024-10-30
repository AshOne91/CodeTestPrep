#include <iostream>
using namespace std;

int board[128][128];
int ans[2];

bool check(int n, int x, int y) {
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            if(board[x+i][y+j] != board[x][y])
                return false;
    return true;
}

void solve(int n, int x, int y) {
    if(check(n, x, y)) 
        ans[board[x][y]]++;
    else {
        n /= 2;
        solve(n, x, y);
        solve(n, x+n, y);
        solve(n, x, y+n);
        solve(n, x+n, y+n);
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin >> board[i][j];
    solve(n, 0, 0);
    for(int a:ans) cout << a << '\n';
}
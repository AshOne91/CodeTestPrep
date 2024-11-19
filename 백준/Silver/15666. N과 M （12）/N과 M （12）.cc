#include <stdio.h>
#include <algorithm>
int n, m, arr[8], num[8];
void seq(int x, int len) {
    if (len == m) {
        for (int i = 0; i < m; i++) printf("%d ", arr[i]);
        printf("\n");
        return;
    }
    for (int i = x, last = 0; i < n; i++) {
        if (num[i] != last) {
            arr[len] = last = num[i];
            seq(i, len + 1);
        }
    }
}
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%d", &num[i]);
    std::sort(num, num + n);
    seq(0, 0);
}

#include <iostream>
#include <vector>
using namespace std;

vector<int> preorder; // 전위 순회 입력 저장

// 후위 순회 출력 함수
void PostOrder(int start, int end) {
    if (start > end) return; // 범위가 비어있으면 종료

    int root = preorder[start]; // 현재 서브트리의 루트 노드
    int idx = start + 1;

    // 왼쪽 서브트리의 끝을 찾기 (root보다 큰 값이 나오는 지점)
    while (idx <= end && preorder[idx] < root) {
        idx++;
    }

    // 왼쪽 서브트리 처리
    PostOrder(start + 1, idx - 1);
    // 오른쪽 서브트리 처리
    PostOrder(idx, end);
    // 현재 노드 출력 (후위 순회)
    cout << root << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int value;
    while (cin >> value) {
        preorder.push_back(value); // 전위 순회 결과 입력
    }

    PostOrder(0, preorder.size() - 1); // 후위 순회 출력
    return 0;
}

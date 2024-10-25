#include <iostream>
#include <queue>

using namespace std;

int N, M, x, y;
int moving[101], record[101];

void BFS(int start) {
	queue < pair<int, int>> q;
	q.push(make_pair(start, 0));
	record[start] = 0;

	while (!q.empty()) {
		int now = q.front().first;
		int count = q.front().second;
		q.pop();

		for (int i = 1; i <= 6; i++) {
			int tempCount = count; // 6번 모두 같은 횟수에서 계산되어야하므로 임시변수 이용
			if (now + i > 100) // 주사위를 던져서 100을 넘어가면 pass
				continue;
			int next = now + i; // 주사위 돌린 이후 값
			tempCount++;
			if (moving[next] != 0) { // 만약 주사위로 이동한 위치에 뱀 또는 사다리가 있다면
				next = moving[next];
			}
			if (record[next] > tempCount) { // 이동 후 기존 주사위 횟수보다 더 적은 횟수로 도착할 수 있다면
				record[next] = tempCount;
				q.push(make_pair(next, tempCount));
			}
		}
	}
	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= 100; i++) {
		record[i] = 987654321;
	}
	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		moving[x] = y;
	}
	for (int i = 0; i < M; i++) {
		cin >> x >> y;
		moving[x] = y;
	}

	BFS(1);

	cout << record[100];
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <cmath>
#include <limits>

using namespace std;
const int INF = std::numeric_limits<int>::max();
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    std::cin>>N>>K;
    std::vector<int> dist(100000 + 1, INF);
    std::deque<int> dq;

    dq.push_back(N);
    dist[N] = 0;

    while(!dq.empty())
    {
        int pos = dq.front();
        dq.pop_front();

        if (pos == K)
        {
            std::cout<<dist[pos];
            return 0;
        }

        int next_pos = pos - 1;
        if (next_pos >= 0 && dist[next_pos] > dist[pos] + 1)
        {
            dq.push_back(next_pos);
            dist[next_pos] = dist[pos] + 1;
        }
        next_pos = pos + 1;
        if (next_pos < 100001 && dist[next_pos] > dist[pos] + 1)
        {
            dq.push_back(next_pos);
            dist[next_pos] = dist[pos] + 1;
        }

        next_pos = pos * 2;
        if (next_pos < 100001 && dist[next_pos] > dist[pos])
        {
            dq.push_front(next_pos);
            dist[next_pos] = dist[pos];
        }
    }
    return 0;
}
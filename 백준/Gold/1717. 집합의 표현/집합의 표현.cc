#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <cmath>

using namespace std;

class union_find
{
    private:
    std::vector<int> _parent;
    std::vector<int> _rank;

    public:
    union_find(int n)
    {
        for (int i = 0; i < n+1; ++i)
        {
            _parent.push_back(i);
            _rank.push_back(0);
        }
    }

    int find(int x)
    {
        if (_parent[x] != x)
        {
            _parent[x] = find(_parent[x]);
        }
        return _parent[x];
    }

    void unite(int x, int y)
    {
        int root_x = find(x);
        int root_y = find(y);
        if (root_x == root_y)
        {
            return;
        }

        if (_rank[root_x] < _rank[root_y])
        {
            _parent[root_x] = root_y;
        }
        else if (_rank[root_x] > _rank[root_y])
        {
            _parent[root_y] = root_x;
        }
        else
        {
            _parent[root_y] = root_x;
            _rank[root_x]++;
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // 문제 풀이 코드 작성
    int n, m;
    std::cin>>n>>m;
    union_find un = union_find(n);
    for (int i = 0; i < m; ++i)
    {
        int cmd, a, b;
        std::cin>>cmd>>a>>b;
        if (cmd == 0)
        {
            un.unite(a, b);
        }
        else
        {
            if (un.find(a) == un.find(b))
            {
                std::cout<<"yes"<<'\n';
            }
            else
            {
                std::cout<<"no"<<'\n';
            }
        }
    }
    return 0;
}

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class CUnion
{
  private:
    vector<int> _parent;
    vector<int> _rank;
    
  public:
    CUnion(int size) : _parent(size, - 1), _rank(size, 0){}
    
    int find(int node)
    {
        if (_parent[node] == -1)
            return node;
        
        return _parent[node] = find(_parent[node]);
    }
    
    void unionParent(int node1, int node2)
    {
        int root1 = find(node1);
        int root2 = find(node2);
        
        if (_rank[root1] > _rank[root2])
        {
            _parent[root2] = root1;
        } 
        else if (_rank[root1] < _rank[root2])
        {
            _parent[root1] = root2;
        }
        else
        {
            _parent[root2] = root1;
            _rank[root1]++;
        }
    }
    
    bool isCycle(int node1, int node2)
    {
        return find(node1) == find(node2);
    }
};

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    sort(costs.begin(), costs.end(), [](const vector<int>& lhs, const vector<int>& rhs)
         {
            return lhs[2] < rhs[2];
         });
    
    CUnion jointSet(n);
    for(int i = 0; i < costs.size(); ++i)
    {
        int cost = costs[i][2];
        int node1 = costs[i][0];
        int node2 = costs[i][1];
        
        if (!jointSet.isCycle(node1, node2))
        {
            jointSet.unionParent(node1, node2);
            answer += cost;
        }
    }
    return answer;
}
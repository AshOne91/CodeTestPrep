#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

// x좌표 기준으로 뽑음
unordered_map </*x*/int, /*pos*/int> posMap;

struct node
{
    int x = -1;
    int y = -1;
    node *left = nullptr;
    node *right = nullptr;
};

class Tree
{
  public:
    node* root = nullptr;
    
    node* createNode(const vector<int>& nodePoint)
    {
        node* newNode = new node;
        newNode->x = nodePoint[0];
        newNode->y = nodePoint[1];
        return newNode;
    }
    
    void addNode(const vector<int>& nodePoint)
    {
        auto newNode = createNode(nodePoint);
        if (root == nullptr)
        {
            root = newNode;
            return;
        }
        
        auto temp = root;
        while(true)
        {
            // 자식 같은 y좌표를 가진다
            // 자식 노드느의 y 값은 항상 부모 노드보다 작다
            // 왼쪽 서브 트리의 x 값은 작다
            
            // 왼쪽에 넣고 시작하기
            if(newNode->x < temp->x)
            {
                if (temp->left == nullptr)
                {
                    temp->left = newNode;
                    return;
                }
                else
                {
                    temp = temp->left;
                }
            }
            else
            {
                if (temp->right == nullptr)
                {
                    temp->right = newNode;
                    return;
                }
                else
                {
                    temp = temp->right;
                }
            }            
        }
    }
        
    void Preorder(node* pNode, vector<int>& result)
    {
        if (pNode != nullptr)
        {
            result.push_back(posMap[pNode->x]);
            Preorder(pNode->left, result);
            Preorder(pNode->right, result);
        }
    }
        
    void Postorder(node* pNode, vector<int>& result)
    {
        if (pNode != nullptr)
        {
            Postorder(pNode->left, result);
            Postorder(pNode->right, result);
            result.push_back(posMap[pNode->x]);
        }
    }
};

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    for(int index = 0; index < nodeinfo.size(); ++index)
    {
        posMap[nodeinfo[index][0]] = (index + 1);
    }
    
    // 순서대로 구축하기 위해 y축 기준(x순서로 정렬)
    sort(nodeinfo.begin(), nodeinfo.end(),[](const vector<int>& lhs, const vector<int>& rhs){
        
        if (lhs[1] != rhs[1])
        {
            return lhs[1] > rhs[1];
        }
        
        return lhs[0] < rhs[0];
    });
    
    Tree* newTree = new Tree;
    for(auto& node : nodeinfo)
    {
        newTree->addNode(node);
    }
    
    vector<vector<int>> answer;
    
    vector<int> result;
    newTree->Preorder(newTree->root, result);
    answer.push_back(result);
    result.clear();
    
    newTree->Postorder(newTree->root, result);
    answer.push_back(result);
    result.clear();
    
    return answer;
}
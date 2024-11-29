#include <iostream>
#include <unordered_map>

class Node {
public:
    char value = '.';
    char left = '.';
    char right = '.';
};

class Tree {
public:
    char root = '.';
    std::unordered_map<char, Node> list;

    void insert(char node, char left, char right) {
        if (root == '.') { root = node; }
        list[node].left = left;
        list[node].right = right;
    }

    void preorder(char node) {
        if (node == '.') return;
        std::cout << node;
        preorder(list[node].left);
        preorder(list[node].right);
    }

    void inorder(char node) {
        if (node == '.') return;
        inorder(list[node].left);
        std::cout << node;
        inorder(list[node].right);
    }

    void postorder(char node) {
        if (node == '.') return;
        postorder(list[node].left);
        postorder(list[node].right);
        std::cout << node;
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N;
    std::cin >> N;

    Tree tr;

    for (int i = 0; i < N; ++i) {
        char node, left, right;
        std::cin >> node >> left >> right;
        tr.insert(node, left, right);
    }

    tr.preorder(tr.root);
    std::cout << '\n';
    tr.inorder(tr.root);
    std::cout << '\n';
    tr.postorder(tr.root);
    std::cout << '\n';

    return 0;
}

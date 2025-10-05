#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

// Huffman Tree Node
struct Node {
    char ch;
    int freq;
    Node *left, *right;

    Node(char c, int f) {
        ch = c;
        freq = f;
        left = right = nullptr;
    }
};

struct Compare {
    bool operator()(Node* l, Node* r) {
        return l->freq > r->freq;
    }
};

void preorder(Node* root, string code) {
    if (!root) return;

    if (!root->left && !root->right && root->ch != '#') {
        cout << code << " ";
    }

    preorder(root->left, code + "0");
    preorder(root->right, code + "1");
}

int main() {
    string S = "abcdef";
    int f[] = {5, 9, 12, 13, 16, 45};
    int n = S.size();

    // Min-heap priority queue
    priority_queue<Node*, vector<Node*>, Compare> pq;

    for (int i = 0; i < n; i++) {
        pq.push(new Node(S[i], f[i]));
    }

    // Build Huffman Tree
    while (pq.size() > 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();

        Node* merged = new Node('#', left->freq + right->freq);
        merged->left = left;
        merged->right = right;

        pq.push(merged);
    }
   
    Node* root = pq.top();

    preorder(root, "");

    return 0;
}

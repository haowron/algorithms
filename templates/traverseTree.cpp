#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define rep(i, n) for (int i = 0; i < n; ++i)
#define repr(e, i) for (auto e : i)
#define all(x) x.begin(), x.end()
#define pii pair<int, int>

using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 33;
const long long mod = 1000000007;
const int dirx[] = {1, 0, -1, 0};
const int diry[] = {0, 1, 0, -1};
typedef long long ll;

struct Node {
    int val;
    Node* left;
    Node* right;
};

void travePre(Node* node) {
    // val -> left -> right
    if (!node) return;
    printf("%d ", node->val);
    travePre(node->left);
    travePre(node->right);
}
void travePre2(Node* node) {
    // 将所有的右节点压栈待处理，不停迭代左节点
    if (!node) return;
    stack<Node*> stk;
    Node* cur = node;
    while (true) {
        while (cur) {
            printf("%d ", cur->val);
            if (cur->right) stk.push(cur->right);
            cur = cur->left;
        }
        if (stk.empty()) return;
        cur = stk.top();
        stk.pop();
    }
}
void traveIn(Node* node) {
    // left -> val -> right
    if (!node) return;
    traveIn(node->left);
    printf("%d ", node->val);
    traveIn(node->right);
}
void traveIn2(Node* node) {
    // left -> val -> right
    if (!node) return;
    stack<Node*> stk;
    Node* cur = node;
    while (true) {
        while (cur) {
            stk.push(cur);
            cur = cur->left;
        }
        if (stk.empty()) return;
        cur = stk.top();
        stk.pop();
        printf("%d ", cur->val);
        cur = cur->right;
    }
}
void travePost(Node* node) {
    // left -> right -> val
    if (!node) return;
    travePost(node->left);
    travePost(node->right);
    printf("%d ", node->val);
}
void travePost2(Node* node) {
    if (!node) return;
    stack<Node*> stk;
    Node* prev = nullptr;
    Node* cur = node;
    while (cur || !stk.empty()) {
        while (cur) {
            stk.emplace(cur);
            cur = cur->left;
        }
        cur = stk.top();
        stk.pop();
        if (!cur->right || cur->right == prev) {
            printf("%d ", cur->val);
            prev = cur;
            cur = nullptr;
        } else {
            stk.emplace(cur);
            cur = cur->right;
        }
    }
}

int main() {
#ifdef AZUKI_LOCAL
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif
    vector<Node> nodes;
    rep(i, 10) {
        nodes.push_back(Node{i, nullptr, nullptr});
    }
    nodes[3].left = &nodes[2];
    nodes[3].right = &nodes[8];
    nodes[2].left = &nodes[0];
    nodes[0].right = &nodes[1];
    nodes[8].left = &nodes[5];
    nodes[8].right = &nodes[9];
    nodes[5].left = &nodes[4];
    nodes[5].right = &nodes[6];
    nodes[6].right = &nodes[7];
    /*
            3
          /   \
        2       8
      /       /   \
    0        5     9
      \     / \
        1  4   6
                \
                 7
    */

    printf("TravePre\n");
    travePre(&nodes[3]);
    printf("\n");
    travePre2(&nodes[3]);
    printf("\nTraveIn\n");
    traveIn(&nodes[3]);
    printf("\n");
    traveIn2(&nodes[3]);
    printf("\nTravePost\n");
    travePost(&nodes[3]);
    printf("\n");
    travePost2(&nodes[3]);
    printf("\n");
    return 0;
}
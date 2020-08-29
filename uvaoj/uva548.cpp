#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cstdlib>

#define rep(i, n) for (int i = 0; i < n; ++i)
#define repr(e, i) for (auto e: i)
#define all(x) x.begin(), x.end()


using namespace std;
const int MAXN = 10e4 + 5;
const int INF = 0x3f3f3f3f;
typedef long long ll;

// data: 节点值
// value: 最小节点值
// leaf: 取得最小节点值的叶子节点
typedef struct node {
    int data = 0, left = 0, right = 0, value = INF, leaf = 0;
};

vector<node> tree;

int create_tree(vector<int> inorder, vector<int> postorder) {
    if (inorder.empty()) return 0;
    node n;
    n.data = postorder[postorder.size() - 1];
    vector<int> v[2][2];
    int is_right = 0;
    for (int i = 0; i < inorder.size(); ++i) {
        if (inorder[i] == n.data) {
            is_right = 1;
            continue;
        }
        v[is_right][0].push_back(inorder[i]);
        v[is_right][1].push_back(postorder[i - is_right]);
    }
    n.left = create_tree(v[0][0], v[0][1]);
    n.right = create_tree(v[1][0], v[1][1]);
    n.value = n.data;
    if (tree[n.left].value == INF && tree[n.right].value == INF) {
        n.leaf = n.data;
    } else if (tree[n.left].value == tree[n.right].value) {
        n.data += tree[n.left].value;
        n.leaf = min(tree[n.left].leaf, tree[n.right].leaf);
    } else if (tree[n.left].value < tree[n.right].value) {
        n.value += tree[n.left].value;
        n.leaf = tree[n.left].leaf;
    } else {
        n.value += tree[n.right].value;
        n.leaf = tree[n.right].leaf;
    }
    tree.push_back(n);
    return tree.size() - 1;
}


int main() {
#ifdef AZUKI_LOCAL
    freopen("../input.txt", "r", stdin);
    //freopen("../output.txt", "w", stdout);
#endif
    string s1, s2;
    while (true) {
        tree.clear();
        // 建立空节点
        tree.emplace_back();
        vector<int> inorder, postorder;
        getline(cin, s1);
        if (s1.empty()) break;
        stringstream ss1(s1);
        int num;
        while (ss1 >> num) {
            inorder.push_back(num);
        }
        getline(cin, s2);
        stringstream ss2(s2);
        while (ss2 >> num) {
            postorder.push_back(num);
        }
        int root = create_tree(inorder, postorder);
        cout << tree[root].leaf << endl;

    }
    return 0;
}

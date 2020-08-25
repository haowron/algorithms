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
const int MAXN = 10e4;
const int INF = 0x3f3f3f3f;
typedef long long ll;

typedef struct {
    string s = "";
    int next_node = -1;
} node;

vector<node> v;

int idx = 0, cur_node = 0, last_node = 0;
char str[MAXN];

void insert_node() {
    node n;
    str[idx] = '\0';
    idx = 0;
    n.s = string(str);

    auto cur = v[cur_node];
    n.next_node = cur.next_node;
    cur.next_node = v.size();
    v[cur_node] = cur;

    if (last_node == cur_node) last_node = v.size();
    cur_node = v.size();
    v.push_back(n);
}

int main() {
#ifdef AZUKI_LOCAL
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    string s;
    while (cin >> s) {
        v.clear();
        idx = cur_node = last_node = 0;
        v.emplace_back();
        for (char c : s) {
            if (c == '[') {
                insert_node();
                cur_node = 0;
            } else if (c == ']') {
                insert_node();
                cur_node = last_node;
            } else {
                str[idx++] = c;
            }
        }
        insert_node();
        int i = v[0].next_node;
        while (i != -1) {
            cout << v[i].s;
            i = v[i].next_node;
        }
        cout << endl;
    }
    return 0;
}

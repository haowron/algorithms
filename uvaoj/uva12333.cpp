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
    int fib = -1;
    int child[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
} Node;

vector<Node> T;

void insert_v(const char *c, int fib) {
    ll idx = 0;
    auto cur_node = T[idx];
    int strip = -1;
    for (int i = 58; i >= 0; --i) {
        int cur_c = *(c + i);
        if (strip && cur_c) strip = 0;
        if (strip == -1) continue;
        if (strip == 40) break;
        ++strip;

        if (cur_node.child[cur_c]) {
            idx = cur_node.child[cur_c];
            cur_node = T[idx];
        } else {
            cur_node.child[cur_c] = T.size();
            Node n;
            n.fib = fib;
            T.push_back(n);
            T[idx] = cur_node;
            idx = T.size() - 1;
            cur_node = T[idx];
        }
    }
}

void init() {
    T.emplace_back();
    char fibs[2][65];
    memset(fibs, 0, sizeof(fibs));
    int p, q, x, offset[2];
    offset[0] = 0;
    offset[1] = 0;
    fibs[0][0] = 1;
    fibs[1][0] = 1;
    insert_v(fibs[0], 0);
    rep(i, 99998) {
        p = (i & 1);
        q = !p;
        rep(j, 56) {
            // 由于进位，这里应该有offset
            fibs[p][j] = fibs[p][j + offset[p]] + fibs[q][j + offset[q]] + x;
            if (fibs[p][j] > 9) {
                fibs[p][j] -= 10;
                x = 1;
            } else {
                x = 0;
            }
        }
        if (offset[p]) offset[p] = 0;
        if (fibs[p][55]) {
            offset[0] = 1;
            offset[1] = 1;
        }
        insert_v(fibs[p], i + 2);
    }
}

int solve(string str_num) {
    int next_node_idx = 0;
    auto cur_node = T[next_node_idx];
    rep(i, str_num.size()) {
        int e = str_num[i] - '0';
        if (cur_node.child[e]) {
            next_node_idx = cur_node.child[e];
            cur_node = T[next_node_idx];
        } else {
            next_node_idx = -1;
            break;
        }
    }
    if(next_node_idx == -1) return -1;
    return T[next_node_idx].fib;
}

int main() {
#ifdef AZUKI_LOCAL
    freopen("../input.txt", "r", stdin);
    //freopen("../output.txt", "w", stdout);
#endif
    int kase = 0;
    string num;
    init();
    cin >> kase;
    rep(k, kase) {
        cin >> num;
        printf("Case #%d: %d\n", k + 1, solve(num));
    }
    return 0;
}

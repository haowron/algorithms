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
#include <unordered_set>
#include <unordered_map>


#define rep(i, n) for (int i = 0; i < n; ++i)
#define repr(e, i) for (auto e: i)
#define all(x) x.begin(), x.end()
#define pii pair<int, int>

// https://atcoder.jp/contests/typical90/tasks/typical90_l


using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 33;
typedef long long ll;
const long long mod = 1000000007;

map<pii, pii > G;

int dirx[] = {1, 0, -1, 0};
int diry[] = {0, 1, 0, -1};

pii get_parent(pii p) {
    pii p2 = p;
    while (true) {
        auto p_point = G.find(p);
        if (p_point == G.end() || p_point->second == p) break;
        p = G[p];
    }
    while (true) {
        auto p_point = G.find(p2);
        if (p_point == G.end() || p_point->second == p) break;
        pii p3 = G[p2];
        G[p2] = p;
        p2 = p3;
    }
    return p;
}

void color(pii p) {
    rep(i, 4) {
        pii neighbour = {p.first + dirx[i], p.second + diry[i]};
        if (G.find(neighbour) == G.end()) continue;
        pii parent = get_parent(neighbour);
        G[get_parent(p)] = parent;
    }
    if (G.find(p) == G.end()) G[p] = p;
}

int main() {
#ifdef AZUKI_LOCAL
    freopen("../input.txt", "r", stdin);
    //freopen("../output.txt", "w", stdout);
#endif
    int h, w, q, t, r, c, rb, cb;
    while (cin >> h >> w >> q) {
        G.clear();
        rep(i, q) {
            scanf("%d", &t);
            if (t == 1) {
                scanf("%d%d", &r, &c);
                color({r, c});
            } else {
                scanf("%d%d%d%d", &r, &c, &rb, &cb);
                if (G.find({r, c}) != G.end() && get_parent({r, c}) == get_parent({rb, cb})) printf("Yes\n");
                else printf("No\n");
            }
        }
    }
    return 0;
}

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
#include <unordered_map>


#define rep(i, n) for (int i = 0; i < n; ++i)
#define repr(e, i) for (auto e: i)
#define all(x) x.begin(), x.end()
#define pii pair<int, int>


using namespace std;
const int maxn = 80 + 5;
const int inf = 0x3f3f3f3f;
typedef long long ll;


struct Node {
    vector<int> v;
    int dist;

    bool operator<(const Node &rhs) const {
        return dist > rhs.dist;
    }
};


void solve(int a, int b, int c, int d) {
    int dis = d;
    if (c < d) {
        dis = d - c;
    } else if (c == d) {
        cout << 0 << " " << d << endl;
        return;
    }
    map<vector<int>, int> G;
    int maxi[] = {a, b, c};
    priority_queue<Node> q;
    vector<int> t;
    t.push_back(0);
    t.push_back(0);
    t.push_back(c);
    Node n;
    n.v = t;
    n.dist = 0;
    q.push(n);
    G[t] = 1;
    int min_dist = 0;
    while (!q.empty()) {
        auto u = q.top();
        q.pop();
        int cnt = G[u.v] + 1;
        rep(k, 3) {
            if (u.v[k] <= d) {
                if (d - u.v[k] < dis) {
                    dis = d - u.v[k];
                    min_dist = u.dist;
                }
            };
        }
        if (dis == 0) {
            cout << u.dist << " " << d << endl;
            return;
        }
        rep(i, 3) {
            rep(j, 3) {
                if (i == j) continue;
                Node v = u;
                // fill water
                int w = v.v[j];
                v.v[j] = min(maxi[j], v.v[i] + v.v[j]);
                v.v[i] = v.v[i] - (v.v[j] - w);
                v.dist += abs(v.v[j] - w);
                if (G.find(v.v) != G.end()) continue;
//                rep(k, 3) cout << v.v[k] << " ";
//                cout << v.dist << endl;

                G[v.v] = cnt;
                q.push(v);
            }
        }
    }
    cout << min_dist << " " << d - dis << endl;
}


int main() {
#ifdef AZUKI_LOCAL
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int kase, a, b, c, d;
    cin >> kase;
    while (kase--) {
        cin >> a >> b >> c >> d;
        solve(a, b, c, d);
    }

}

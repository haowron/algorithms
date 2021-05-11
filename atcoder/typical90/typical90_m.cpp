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

using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 33;
const long long mod = 1000000007;
const int dirx[] = {1, 0, -1, 0};
const int diry[] = {0, 1, 0, -1};
typedef long long ll;


// https://atcoder.jp/contests/typical90/tasks/typical90_m
map<int, vector<pii>> G;
int n;

class cmp {
public:
    bool operator()(const vector<int> &a, const vector<int> &b) {
        return a[2] > b[2];
    };
};

vector<int> dijkstra(int start) {
    priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
    pq.push({start, -1, 0});
    vector<int> visited(n + 1);
    vector<int> distances(n + 1, inf);
    while (!pq.empty()) {
        vector<int> u = pq.top();
        pq.pop();
        if (visited[u[0]]) continue;
        distances[u[0]] = min(distances[u[0]], u[2]);
        visited[u[0]] = u[1];
        repr(e, G[u[0]]) {
            if (visited[e.first]) continue;
            pq.push({e.first, u[0], e.second + u[2]});
        }
    }
    return distances;
}


int main() {
#ifdef AZUKI_LOCAL
    freopen("../input.txt", "r", stdin);
    //freopen("../output.txt", "w", stdout);
#endif
    int m, a, b, c;
    while (cin >> n >> m) {
        G.clear();
        rep(i, m) {
            scanf("%d%d%d", &a, &b, &c);
            G[a].push_back({b, c});
            G[b].push_back({a, c});
        }
        vector<int> path1 = dijkstra(1);
        vector<int> path2 = dijkstra(n);
        for (int i = 1; i <= n; ++i) {
            printf("%d\n", path1[i] + path2[i]);
        }
    }
    return 0;
}

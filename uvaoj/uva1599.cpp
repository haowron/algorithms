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
const int maxn = 100000 + 5;
const int inf = 0x3f3f3f3f;
typedef long long ll;


typedef struct {
    int start, end, color;
} edge;

vector<int> G[maxn];
vector<edge> edges;


void add_edges(int start, int end, int color) {
    G[start].push_back(edges.size());
    edges.push_back(edge{start = start, end = end, color = color});
}

int main() {
#ifdef AZUKI_LOCAL
    freopen("../input.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
    int start, end, color;
    int m, n;
    while (cin >> n >> m) {
        rep(i, n + 5) {
            G[i].clear();
        }
        edges.clear();
        rep(i, m) {
            scanf("%d%d%d", &start, &end, &color);
            add_edges(start, end, color);
            add_edges(end, start, color);
        }


        queue<int> q;
        q.push(n);
        int visited[n + 5];
        memset(visited, 0, sizeof(visited));
        visited[n] = 1;
        int eof = inf;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            int cur = visited[u] + 1;
            if (cur > eof) break;

            repr(idx, G[u]) {
                int v = edges[idx].end;
                if (visited[v]) continue;
                visited[v] = cur;
                q.push(v);
                if (v == 1) {
                    eof = cur;
                }
            }
        }
        int vis[maxn];
        memset(vis, 0, sizeof(vis));
        vis[1] = true;
        vector<int> ans;
        int cur = visited[1] - 1;
        vector<int> cur_points;
        cur_points.push_back(1);
        while (cur > 0) {
            int min_color = inf;
            repr(cur_point, cur_points) {
                repr(v, G[cur_point]) {
                    edge e = edges[v];
                    if (visited[e.end] == cur && e.color < min_color) min_color = e.color;
                }
            }
            vector<int> new_cur_points;
            repr(cur_point, cur_points) {
                repr(v, G[cur_point]) {
                    edge e = edges[v];
                    if (visited[e.end] == cur && !vis[e.end] && e.color == min_color) {
                        new_cur_points.push_back(e.end);
                        vis[e.end] = true;
                    }
                }
            }
            ans.push_back(min_color);
            --cur;
            cur_points = new_cur_points;
        }
        cout << ans.size() << endl << ans[0];
        for (int i = 1; i < ans.size(); ++i) {
            cout << " " << ans[i];
        }
        cout << endl;
    }
    return 0;
}

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
const int maxn = 105;
const int inf = 0x3f3f3f3f;
typedef long long ll;

int visited[maxn];
int visiting[maxn];
int g[maxn][maxn];
int m, n;
vector<int> ans;


bool dfs(int u) {
    visiting[u] = 1;
    for (int i = 1; i <= m; ++i) {
        if (g[u][i]) {
            if (visited[i]) continue;
            if (visiting[i]) return false;
            dfs(i);
        }
    }
    visited[u] = 1;
    ans.push_back(u);
    return true;
}


// dfs的迭代写法，优先输出较深节点
bool solve() {
    for (int i = 1; i <= m; ++i) {
        if (visited[i]) continue;
        if (!dfs(i)) return false;
    }
    return true;
}

int main() {
#ifdef AZUKI_LOCAL
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    while (cin >> m >> n) {
        if (!m) break;
        memset(g, 0, sizeof(g));
        int u, v;
        while (n--) {
            cin >> u >> v;
            g[u][v] = 1;
        }
        ans.clear();
        memset(visited, 0, sizeof(visited));
        memset(visiting, 0, sizeof(visiting));
        if (solve()) {
            for (int j = ans.size() - 1; j > 0; --j) {
                cout << ans[j] << " ";
            }
            cout << ans[0] << endl;
        } else {
            // 题目没有规定错误情况下输出什么。
            cout << "NO" << endl;
        }
    }
    return 0;
}

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
const int maxn = 1000;
typedef long long ll;

// https://atcoder.jp/contests/typical90/tasks/typical90_c
// https://github.com/E869120/kyopro_educational_90/blob/main/editorial/003.jpg

int n;
vector<vector<int>> G;

pii bfs(int start) {
    vector<int> visited(n);
    queue<int> q;
    q.push(start);
    visited[start] = 1;
    int x;
    int u;
    while(!q.empty()){
        u = q.front();
        q.pop();
        x = visited[u] + 1;
        for(int v:G[u]) {
            if(visited[v]) continue;
            visited[v] = x;
            q.push(v);
        }
    }
    return {x, u};
}


int main() {
#ifdef AZUKI_LOCAL
    freopen("../input.txt", "r", stdin);
    //freopen("../output.txt", "w", stdout);
#endif
    while (cin >> n) {
        G = vector<vector<int>>(n);
        rep(i, n - 1) {
            int a, b;
            cin >> a >> b;
            --a;
            --b;
            G[a].push_back(b);
            G[b].push_back(a);
        }
        cout << bfs(bfs(0).second).first - 1 << endl;
    }

    return 0;
}

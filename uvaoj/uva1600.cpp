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
#define pii pair<int, int>


using namespace std;
const int maxn = 100000 + 5;
const int inf = 0x3f3f3f3f;
typedef long long ll;


const int dir_x[] = {1, -1, -1, 1};
const int dir_y[] = {1, 1, -1, -1};


int main() {
#ifdef AZUKI_LOCAL
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int kase;
    cin >> kase;
    while (kase--) {
        int m, n, k;
        cin >> m >> n >> k;
        int G[m][n], visited[m][n];
        memset(visited, 0x3f, sizeof(visited));
        rep(i, m) {
            rep(j, n) {
                cin >> G[i][j];
            }
        }
        queue<pii > q;
        q.push({0, 0});
        visited[0][0] = 1;
        while (!q.empty()) {
            pii u = q.front();
            q.pop();
            int cur = visited[u.first][u.second];
            // 原题的turbo mode是可以拐弯的，而不是一条直线走到底
            rep(i, k + 2) {
                rep(j, k + 2) {
                    rep(d, 4) {
                        int dir = i + j;
                        if (dir > k + 1) continue;
                        pii v = {u.first + i * dir_x[d], u.second + j * dir_y[d]};
                        if (v.first < 0 || v.first >= m || v.second < 0 || v.second >= n ||
                            visited[v.first][v.second] <= cur + dir || G[v.first][v.second])
                            continue;
                        visited[v.first][v.second] = cur + dir;
                        q.push(v);
                    }
                }
            }
        }
        if (visited[m - 1][n - 1] > 10000000) cout << -1 << endl;
        else cout << visited[m - 1][n - 1] - 1 << endl;
    }
    return 0;
}

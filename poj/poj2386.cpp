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

#define rep(i, n) for (int i = 0; i < n; ++i)
#define all(x) x.begin(), x.end()


using namespace std;
const int MAXN = 10e5 + 5;
const int INF = 0x7f7f7f7f;
typedef long long ll;

string pool[105];
int xx[] = {1, 0, -1, 0, 1, 1, -1, -1};
int yy[] = {0, 1, 0, -1, 1, -1, 1, -1};
int X, Y;

void fill_water(int x, int y) {
    queue<pair<int, int> > q;
    q.push({x, y});
    pool[x][y] = '.';
    while (!q.empty()) {
        auto p = q.front();
        q.pop();
        int x_ = p.first, y_ = p.second;

        rep(i, 8) {
            if ((x_ + xx[i]) < 0 || x_ + xx[i] >= X || (y_ + yy[i]) < 0 || (y_ + yy[i]) >= Y) continue;
            if (pool[x_ + xx[i]][y_ + yy[i]] == 'W') {
                pool[x_ + xx[i]][y_ + yy[i]] = '.';
                q.push({x_ + xx[i], y_ + yy[i]});
            }
        }

    }
}

// 遍历练习
int main() {
#ifndef ONLINE_JUDGE
    //freopen("../input.txt", "r", stdin);
    //freopen("../output.txt", "w", stdout);
#endif

    cin >> X >> Y;

    rep(i, X) {
        cin >> pool[i];
    }
    int ans = 0;
    rep(i, X) {
        rep(j, Y) {
            if (pool[i][j] == 'W') {
                fill_water(i, j);
                ++ans;
            }
        }
    }
    cout << ans << endl;
    return 0;
}

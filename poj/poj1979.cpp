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

string pool[25];
int xx[] = {1, 0, -1, 0, 1, 1, -1, -1};
int yy[] = {0, 1, 0, -1, 1, -1, 1, -1};
int X, Y;

int fill_black(int startx, int starty) {
    int x, y, newx, newy;
    int ans = 0;
    queue<pair<int, int> > q;
    q.push({startx, starty});
    while (!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        ++ans;
        rep(i, 4) {
            newx = x + xx[i];
            newy = y + yy[i];
            if (newx >= X || newx < 0 || newy < 0  || newy >= Y || pool[newx][newy] != '.') continue;
            pool[newx][newy] = '@';
            q.push({newx, newy});
        }
    }
    return ans;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    //freopen("../output.txt", "w", stdout);
#endif
    while (cin >> Y >> X) {
        if (!X) break;
        int startx, starty;
        rep(i, X) {
            cin >> pool[i];
            rep(j, Y) {
                if (pool[i][j] == '@') {
                    startx = i;
                    starty = j;
                }
            }
        }
        cout << fill_black(startx, starty) << endl;
    }
    return 0;
}

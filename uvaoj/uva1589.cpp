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
const int MAXN = 10e5 + 5;
const int INF = 0x7f7f7f7f;
typedef long long ll;


// 格式化输入与输出
int main() {
#ifndef ONLINE_JUDGE
    //freopen("../input.txt", "r", stdin);
    //freopen("../output.txt", "w", stdout);
#endif
    int xx[] = {1, 0, -1, 0};
    int yy[] = {0, 1, 0, -1};
    int a, b, c;
    char m[30][30]; // 棋盘棋子
    int ans[30][30]; // 不会被将死的位置

    while (cin >> a >> b >> c) {
        if (!a) break;
        b = b + 5;
        c = c + 5;
        memset(ans, 0, sizeof(ans));
        memset(m, 0, sizeof(m));
        char cs[a];
        int xs[a];
        int ys[a];
        rep(i, a) {
            cin >> cs[i] >> xs[i] >> ys[i];
            // 不用判断边界
            xs[i] = xs[i] + 5;
            ys[i] = ys[i] + 5;
            m[xs[i]][ys[i]] = cs[i];
        }
        bool k = false;
        rep(i, a) {
            if (cs[i] == 'G' || cs[i] == 'R') {
                int x_ = xs[i], y_ = ys[i];
                while (true) {
                    --y_;
                    ans[x_][y_] = 1;
                    if (y_ < 1 || m[x_][y_]) break;
                }
                x_ = xs[i], y_ = ys[i];
                while (true) {
                    ++y_;
                    ans[x_][y_] = 1;
                    if (y_ > 25 || m[x_][y_]) break;
                }
                x_ = xs[i], y_ = ys[i];
                while (true) {
                    ++x_;
                    ans[x_][y_] = 1;
                    if (x_ > 25 || m[x_][y_]) break;
                }
                x_ = xs[i], y_ = ys[i];
                while (true) {
                    --x_;
                    ans[x_][y_] = 1;
                    if (x_ < 1 || m[x_][y_]) break;
                }
            } else if (cs[i] == 'H') {
                int x_ = xs[i], y_ = ys[i];
                if (!m[x_ + 1][y_]) {
                    ans[x_ + 2][y_ - 1] = 1;
                    ans[x_ + 2][y_ + 1] = 1;
                }
                if (!m[x_ - 1][y_]) {
                    ans[x_ - 2][y_ - 1] = 1;
                    ans[x_ - 2][y_ + 1] = 1;
                }
                if (!m[x_][y_ + 1]) {
                    ans[x_ + 1][y_ + 2] = 1;
                    ans[x_ - 1][y_ + 2] = 1;
                }
                if (!m[x_][y_ - 1]) {
                    ans[x_ + 1][y_ - 2] = 1;
                    ans[x_ - 1][y_ - 2] = 1;
                }
            } else {
                int x_ = xs[i], y_ = ys[i];
                int con = 0;
                while (true) {
                    ++y_;
                    if (con) ans[x_][y_] = 1;
                    if ((con && m[x_][y_]) || y_ > 25) break;
                    if (m[x_][y_]) {
                        con = 1;
                    }
                }
                x_ = xs[i], y_ = ys[i];
                con = 0;
                while (true) {
                    --y_;
                    if (con) ans[x_][y_] = 1;
                    if((con && m[x_][y_])|| y_ < 1) break;
                    if (m[x_][y_]) {
                        con = 1;
                    }
                }
                x_ = xs[i], y_ = ys[i];
                con = 0;
                while (true) {
                    ++x_;
                    if (con) ans[x_][y_] = 1;
                    if ((con && m[x_][y_]) || x_ > 25) break;
                    if (m[x_][y_]) {
                        con = 1;
                    }
                }
                x_ = xs[i], y_ = ys[i];
                con = 0;
                while (true) {
                    --x_;
                    if (con) ans[x_][y_] = 1;
                    if ((con && m[x_][y_]) || x_ < 1) break;
                    if (m[x_][y_]) {
                        con = 1;
                    }
                }
            }
        }
        rep(i, 4) {
            int newx = b + xx[i], newy = c + yy[i];
            if (newx < 6 || newx > 8 || newy < 9 || newy > 11) continue;
            if (!ans[newx][newy]) {
                k = true;
                break;
            }
        }
        if (!k) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }

    }
}

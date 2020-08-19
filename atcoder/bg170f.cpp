#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <vector>
#include <set>
#include <stack>
#include <queue>

#define rep(i, n) for (int i = 0; i < n; ++i)
#define all(x) x.begin(), x.end()


using namespace std;
const int MAXN = 1000005;
const int INF = 0x7f7f7f7f;
typedef long long ll;

int h, w, k, x_1, y_1, x_2, y_2;


int main() {
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    //freopen("../output.txt", "w", stdout);
#endif
    cin >> h >> w >> k >> x_1 >> y_1 >> x_2 >> y_2;
    --x_1; --x_2; --y_1;--y_2;
    int pool_ans[h + 5][w + 5];
    char pool[h + 5][w + 5];
    int pool_mark[h + 5][w + 5];
    memset(pool_ans, 0x7f, sizeof(pool_ans));
    memset(pool_mark, 0, sizeof(pool_mark));
    pool_ans[x_1][y_1] = 0;

    rep(i, h) {
        rep(j, w) {
            cin >> pool[i][j];
        }
    }
    queue<pair<int, int>> next_point;
    next_point.push(pair<int, int>(x_1, y_1));
    pool_mark[x_1][y_1] = 1;
    while (pool_ans[x_2][y_2] == 0x7f7f7f7f && !next_point.empty()) {
        pair<int, int> cur_point = next_point.front();
        next_point.pop();
        int x = cur_point.first, y = cur_point.second;
        int cur_ans = pool_ans[x][y] + 1;
        pool[x][y] = '@';
        rep(i, k) {
            if (x + i + 1 >= h || pool[x + i + 1][y] == '@') break;
            pool_ans[x + i + 1][y] = min(pool_ans[x + i + 1][y], cur_ans);
            if (!pool_mark[x + i + 1][y]) {
                pool_mark[x + i + 1][y] = 1;
                next_point.push(pair<int, int>(x + i + 1, y));
            }
        }
        rep(i, k) {
            if (x - i - 1 < 0 || pool[x - i - 1][y] == '@') break;
            pool_ans[x - i - 1][y] = min(pool_ans[x - i - 1][y], cur_ans);
            if (!pool_mark[x - i - 1][y]) {
                pool_mark[x - i - 1][y] = 1;
                next_point.push(pair<int, int>(x - i - 1, y));
            }
        }
        rep(i, k) {
            if (y + i + 1 >= w || pool[x][y + i + 1] == '@') break;
            pool_ans[x][y + i + 1] = min(pool_ans[x][y + i + 1], cur_ans);
            if (!pool_mark[x][y + i + 1]) {
                pool_mark[x][y + i + 1] = 1;
                next_point.push(pair<int, int>(x, y + i + 1));
            }
        }
        rep(i, k) {
            if (y - i - 1 < 0 || pool[x][y - i - 1] == '@') break;
            pool_ans[x][y - i - 1] = min(pool_ans[x][y - i - 1], cur_ans);
            if (!pool_mark[x][y - i - 1]) {
                pool_mark[x][y - i - 1] = 1;
                next_point.push(pair<int, int>(x, y - i - 1));
            }
        }
    }
    if (pool_ans[x_2][y_2]==0x7f7f7f7f){
        cout << -1 << endl;
    } else {
        cout << pool_ans[x_2][y_2] << endl;
    }

    return 0;
}

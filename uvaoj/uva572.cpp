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
const int MAXN = 105;
const int INF = 0x3f3f3f3f;
typedef long long ll;

char matrix[MAXN][MAXN];
int x_arr[] = {1, 0, -1, 0, 1, 1, -1, -1};
int y_arr[] = {0, 1, 0, -1, 1, -1, 1, -1};

void bfs(int x, int y) {
    queue<pair<int, int> > q;
    q.push({x, y});
    matrix[x][y] = '*';
    while (!q.empty()) {
        int x_ = q.front().first, y_ = q.front().second;
        q.pop();
        for (int i = 0; i < 8; ++i) {
            int new_x = x_ + x_arr[i], new_y = y_ + y_arr[i];
            if (new_x < 0 || new_y < 0 || new_x >= MAXN || new_y >= MAXN) continue;
                if (matrix[new_x][new_y] == '@') {
                    matrix[new_x][new_y] = '*';
                    q.push({new_x, new_y});
                }
        }
    }
}

int main() {
#ifdef AZUKI_LOCAL
    freopen("../input.txt", "r", stdin);
    //freopen("../output.txt", "w", stdout);
#endif
    int x, y;
    while (cin >> x >> y) {
        if (!x) break;
        memset(matrix, 0, sizeof(matrix));
        int ans = 0;
        for (int i = 0; i < x; ++i) {
            cin >> matrix[i];
        }
        for (int i = 0; i < x; ++i) {
            for (int j = 0; j < y; ++j) {
                if (matrix[i][j] == '@') {
                    bfs(i, j);
                    ++ans;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}

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

// https://atcoder.jp/contests/typical90/tasks/typical90_d
// 这题卡输入输出，用cin cout 会挂！

int main() {
#ifdef AZUKI_LOCAL
    freopen("../input.txt", "r", stdin);
    //freopen("../output.txt", "w", stdout);
#endif
    int h, w, t;
    while (cin >> h >> w) {
        vector<int> sumx(w);
        vector<int> sumy(h);
        vector<vector<int>> a(h, vector<int>(w));
        rep(i, h) {
            rep(j, w) {
                scanf("%d", &a[i][j]);
                sumy[i] += a[i][j];
                sumx[j] += a[i][j];
            }
        }
        rep(i, h) {
            rep(j, w) {
                printf("%d ", sumx[j] + sumy[i] - a[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}

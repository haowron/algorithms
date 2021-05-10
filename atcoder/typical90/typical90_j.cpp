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

// https://atcoder.jp/contests/typical90/tasks/typical90_j


using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 33;
typedef long long ll;
const long long mod = 1000000007;


int main() {
#ifdef AZUKI_LOCAL
    freopen("../input.txt", "r", stdin);
    //freopen("../output.txt", "w", stdout);
#endif

    int n, c, p, q, l, r;
    while (cin >> n) {
        vector<vector<int>> sums(2, vector<int>(n + 1));
        rep(i, n) {
            cin >> c >> p;
            sums[c - 1][i + 1] = p;
            sums[0][i + 1] += sums[0][i];
            sums[1][i + 1] += sums[1][i];
        }
        cin >> q;
        rep(i, q) {
            cin >> l >> r;
            printf("%d %d\n", sums[0][r] - sums[0][l - 1], sums[1][r] - sums[1][l - 1]);
        }
    }
    return 0;
}

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

// https://atcoder.jp/contests/typical90/tasks/typical90_k


using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 33;
typedef long long ll;
const long long mod = 1000000007;

vector<vector<ll>> dp;


int main() {
#ifdef AZUKI_LOCAL
    freopen("../input.txt", "r", stdin);
    //freopen("../output.txt", "w", stdout);
#endif
    int n;
    while (cin >> n) {
        vector<vector<int>> d(n, vector<int>(3));
        rep(i, n) {
            cin >> d[i][0] >> d[i][1] >> d[i][2];
        }
        sort(all(d));
        int *max_day = &d[n - 1][0];
        dp = vector<vector<ll>>(n + 1, vector<ll>(*max_day + 1));
        rep(i, n) {
            rep(j, *max_day) {
                dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
                if (j + d[i][1] <= d[i][0])
                    dp[i + 1][j + d[i][1]] = max(dp[i + 1][j + d[i][1]], dp[i][j] + d[i][2]);
            }
        }
        ll ans = 0;
        rep(i, *max_day + 1) ans = max(ans, dp[n][i]);
        cout << ans << endl;
    }
    return 0;
}

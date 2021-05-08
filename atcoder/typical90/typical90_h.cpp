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

// https://atcoder.jp/contests/typical90/tasks/typical90_h


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
    int n;
    string s;
    while (cin >> n >> s) {
        int dp[n][7];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = (s[0] == 'a');
        for (int i = 1; i < n; ++i) {
            rep(j, 7) {
                dp[i][j] = dp[i - 1][j];
            }
            if (s[i] == 'a') {
                ++dp[i][0];
            } else if (s[i] == 't') {
                dp[i][1] += dp[i][0];
                dp[i][1] %= mod;
            } else if (s[i] == 'c') {
                dp[i][2] += dp[i][1];
                dp[i][2] %= mod;
            } else if (s[i] == 'o') {
                dp[i][3] += dp[i][2];
                dp[i][3] %= mod;
            } else if (s[i] == 'd') {
                dp[i][4] += dp[i][3];
                dp[i][4] %= mod;
            } else if (s[i] == 'e') {
                dp[i][5] += dp[i][4];
                dp[i][5] %= mod;
            } else if (s[i] == 'r') {
                dp[i][6] += dp[i][5];
                dp[i][6] %= mod;
            }
        }
        cout << dp[n - 1][6] << endl;
    }
    return 0;
}

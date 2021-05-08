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
        int dp[7];
        memset(dp, 0, sizeof(dp));
        dp[0] = (s[0] == 'a');
        for (int i = 1; i < n; ++i) {
            if (s[i] == 'a') {
                ++dp[0];
            } else if (s[i] == 't') {
                dp[1] += dp[0];
                dp[1] %= mod;
            } else if (s[i] == 'c') {
                dp[2] += dp[1];
                dp[2] %= mod;
            } else if (s[i] == 'o') {
                dp[3] += dp[2];
                dp[3] %= mod;
            } else if (s[i] == 'd') {
                dp[4] += dp[3];
                dp[4] %= mod;
            } else if (s[i] == 'e') {
                dp[5] += dp[4];
                dp[5] %= mod;
            } else if (s[i] == 'r') {
                dp[6] += dp[5];
                dp[6] %= mod;
            }
        }
        cout << dp[6] << endl;
    }
    return 0;
}

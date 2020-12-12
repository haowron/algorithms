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
#include <unordered_map>


#define rep(i, n) for (int i = 0; i < n; ++i)
#define repr(e, i) for (auto e: i)
#define all(x) x.begin(), x.end()
#define pii pair<int, int>


using namespace std;
const int maxn = 80 + 5;
const int inf = 0x3f3f3f3f;
typedef long long ll;

ll n, s1, v1, s2, v2;

ll solve() {
    // 优化
    ll n1 = n / s1 / s2 - 1;
    n -= (n1 * s1 * s2);
    ll ans = n1 * max(s1 * v2, s2 * v1);
    // 枚举
    ll ans2 = 0;
    if (s1 > s2) {
        for (ll i = 0; i * s1 <= n; ++i) {
            ll i2 = (n - s1 * i) / s2;
            ans2 = max(ans2, v1 * i + v2 * i2);
        }
    } else {
        for (ll i = 0; i * s2 <= n; ++i) {
            ll i2 = (n - s2 * i) / s1;
            ans2 = max(ans2, v2 * i + v1 * i2);
        }
    }
    return ans + ans2;
}

int main() {
#ifdef AZUKI_LOCAL
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int kase;
    cin >> kase;
    for (int i = 1; i <= kase; ++i) {
        cin >> n >> s1 >> v1 >> s2 >> v2;
        printf("Case #%d: ", i);
        cout << solve() << endl;
    }
}

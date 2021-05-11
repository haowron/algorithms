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
const int maxn = 33;
const long long mod = 1000000007;
const int dirx[] = {1, 0, -1, 0};
const int diry[] = {0, 1, 0, -1};
typedef long long ll;


// https://atcoder.jp/contests/typical90/tasks/typical90_n


int main() {
#ifdef AZUKI_LOCAL
    freopen("../input.txt", "r", stdin);
    //freopen("../output.txt", "w", stdout);
#endif
    int n;
    while (cin >> n) {
        vector<ll> a(n), b(n);
        rep(i, n) cin >> a[i];
        rep(i, n) cin >> b[i];
        sort(all(a));
        sort(all(b));
        ll ans = 0;
        rep(i, n) ans += abs(a[i] - b[i]);
        cout << ans << endl;
    }
    return 0;
}

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
const int maxn = 105;
const int inf = 0x3f3f3f3f;
typedef long long ll;


int main() {
#ifdef AZUKI_LOCAL
    freopen("../input.txt", "r", stdin);
    //freopen("../output.txt", "w", stdout);
#endif
    int k;
    cin >> k;
    ll ans = 0;
    for (ll i = 1; i < k+1; ++i) {
        ll x = (i+k-(k%i)) * (k/i) / 2;
        ans += x;
    }
    cout << ans << endl;
    return 0;
}

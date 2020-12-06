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
#define pii pair<int, int>


using namespace std;
const int maxn = 100000 + 5;
const int inf = 0x3f3f3f3f;
typedef long long ll;


int main() {
#ifdef AZUKI_LOCAL
    freopen("../input.txt", "r", stdin);
    //freopen("../output.txt", "w", stdout);
#endif
    int cnt, kase = 1;
    while (cin >> cnt) {
        int nums[cnt];
        rep(i, cnt) cin >> nums[i];
        ll ans = 0;
        rep(i, cnt) {
            ll cur = nums[i];
            ans = max(ans, cur);
            for (int j = i + 1; j < cnt; ++j) {
                cur *= nums[j];
                ans = max(ans, cur);
            }
        }
        cout << "Case #" << kase << ": The maximum product is " << ans << "." << endl << endl;
        ++kase;
    }
    return 0;
}

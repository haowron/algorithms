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
    int n, m;
    ll k;
    while (cin >> n >> m >> k) {
        vector<ll> a(n), b(m), sum_a, sum_b;
        rep(i, n) {
            cin >> a[i];
        }
        rep(i, m) {
            cin >> b[i];
        }
        int ans = 0;
        sum_a.push_back(0);
        sum_b.push_back(0);
        rep(i, n) {
            if (sum_a[i] > k) break;
            sum_a.push_back(sum_a[i] + a[i]);
        }
        rep(i, m) {
            if (sum_b[i] > k) break;
            sum_b.push_back(sum_b[i] + b[i]);
        }
        int j = (int) sum_b.size() - 1;
        rep(i, sum_a.size()){
            if (sum_a[i] > k) break;
            while (sum_b[j] + sum_a[i] > k) {
                --j;
            }
            ans = max(ans, i + j);
        }
        cout << ans << endl;
    }
    return 0;
}

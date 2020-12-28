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
const int maxn = 14;
const int inf = 0x3f3f3f3f;
typedef long long ll;

int main() {
#ifdef AZUKI_LOCAL
    freopen("../input.txt", "r", stdin);
    //freopen("../output.txt", "w", stdout);
#endif
    int kase;
    cin >> kase;
    while (kase--) {
        int cnt;
        cin >> cnt;
        vector<int> v(cnt);
        rep(i, cnt) cin >> v[i];
        int ans = 0, l = 0, r = 0;
        unordered_map<int, int> us;
        while (r < cnt) {

            if (us.find(v[r]) != us.end() && us[v[r]] >= l) {
                ans = max(ans, r - l);
                l = us[v[r]] + 1;
            }
            us[v[r]] = r;
            ++r;
        }
        ans = max(ans, r - l);
        cout << ans << endl;
    }
    return 0;
}

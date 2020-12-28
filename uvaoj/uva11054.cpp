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
    int cnt;
    while (cin>> cnt){
        if (!cnt) return 0;
        ll ans = 0, t, t2=0;
        rep(i, cnt){
            cin >> t;
            t2 += t;
            ans += abs(t2);
        }
        printf("%lld\n", ans);
    }
    return 0;
}

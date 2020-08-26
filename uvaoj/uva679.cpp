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
const int MAXN = 10e4 + 5;
const int INF = 0x3f3f3f3f;
typedef long long ll;


int main() {
#ifdef AZUKI_LOCAL
    freopen("../input.txt", "r", stdin);
    //freopen("../output.txt", "w", stdout);
#endif
    int kase, d, i, ans;
    cin >> kase;
    while(kase--){
        cin >> d >> i;
        ans = 1;
        int leaf_count = 2;
        while (--d) {
            leaf_count *= 2;
            if (i % 2) {
                ans *= 2;
                i = (i + 1) / 2;
            } else {
                ans = ans * 2 + 1;
                i = i / 2;
            }

        }
        cout << ans % leaf_count << endl;
    }
    return 0;
}

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

typedef struct node {
    int dl = 0, dr = 0, wl = 0, wr = 0, lc = 0, rc = 0, w = 0;
};


int solve() {
    int wl, dl, wr, dr;
    cin >> wl >> dl >> wr >> dr;
    if (!wl) wl = solve();
    if (!wr) wr = solve();
    if (wl == 0 || wr == 0 || wl * dl != wr * dr) return 0;
    return wl + wr;
}


int main() {
#ifdef AZUKI_LOCAL
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int kase;
    cin >> kase;
    while (kase--) {
        cout << (solve() ? "YES" : "NO") << endl;
        if(kase) cout << endl;
    }
    return 0;
}

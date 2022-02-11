#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define rep(i, n) for (int i = 0; i < n; ++i)
#define repr(e, i) for (auto& e : i)
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define max(a, b) a > b ? a : b;
#define min(a, b) a < b ? a : b;

using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 33;
const long long MOD = 1000000007;
const int DIRX[] = {1, 0, -1, 0, 1, 1, -1, -1, 0};
const int DIRY[] = {0, 1, 0, -1, 1, -1, 1, -1, 0};
typedef long long ll;

int check() {
    int wl, dl, wr, dr;
    cin >> wl >> dl >> wr >> dr;
    if (wl == 0) {
        wl = check();
    }
    if (wr == 0) {
        wr = check();
    }
    if (wl < 0 || wr < 0 || wl * dl != wr * dr) {
        return -1;
    }
    return wl + wr;
}

int main() {
#ifdef AZUKI_LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int kase;
    cin >> kase;

    while (kase--) {
        if (check() >= 0) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
        if(kase) printf("\n");
    }
}

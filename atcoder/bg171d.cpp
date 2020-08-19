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

#define rep(i, n) for (int i = 0; i < n; ++i)
#define all(x) x.begin(), x.end()


using namespace std;
const int MAXN = 10e5 + 5;
const int INF = 0x7f7f7f7f;
typedef long long ll;
int m[MAXN];

int main() {
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    //freopen("../output.txt", "w", stdout);
#endif
    int n, q, a;

    memset(m, 0, sizeof(m));
    cin >> n;
    ll ans = 0;
    rep(i, n) {
        cin >> a;
        ans += a;
        ++m[a];
    }
    cin >> q;
    int b, c;
    rep(i, q) {
        cin >> b >> c;
        ans += m[b] * (c - b);
        m[c] = m[c] + m[b];
        m[b] = 0;
        cout << ans << endl;
    }


    return 0;
}

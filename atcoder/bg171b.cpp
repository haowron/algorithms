#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <vector>
#include <set>
#include <stack>
#include <queue>

#define rep(i, n) for (int i = 0; i < n; ++i)
#define all(x) x.begin(), x.end()


using namespace std;
const int MAXN = 1000005;
const int INF = 0x7f7f7f7f;
typedef long long ll;


int main() {
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    //freopen("../output.txt", "w", stdout);
#endif
    int n, k;
    cin >> n >> k;
    vector<int> p(n);
    rep(i, n){
        cin >> p[i];
    }
    sort(all(p));
    ll ans= 0;
    rep(i, k){
        ans += p[i];
    }
    cout << ans << endl;

    return 0;
}

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
    freopen("../output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<int> a(n);
    int ax;
    rep(i, n) {
        cin >> a[i];
        if (i) ax ^= a[i];
        else ax = a[i];
    }
    rep(i, n - 1) {
        cout << (ax ^ a[i]) << " ";
    }
    cout << (ax ^ a[n - 1]) << endl;
    return 0;
}

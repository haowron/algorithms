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
const int MAXN = 10e5 + 5;
const int INF = 0x7f7f7f7f;
typedef long long ll;


int main() {
#ifndef ONLINE_JUDGE
    //freopen("../input.txt", "r", stdin);
    //freopen("../output.txt", "w", stdout);
#endif
    int n, k, m;
    int c, x, y;
    int cur_k, cur_m;
    while (cin >> n >> k >> m) {
        if (!n) break;
        int q[n];
        c = 0;
        cur_k = -1;
        cur_m = n;
        memset(q, 0, sizeof(q));
        while (c != n) {
            if(c) cout << ",";
            x = 0;
            y = 0;
            rep(i, k) {
                cur_k = (cur_k + 1) % n;
                if (q[cur_k]) --i;
            }
            rep(i, m) {
                cur_m = (cur_m + n - 1) % n;
                if (q[cur_m]) --i;
            }
            if (cur_k == cur_m) {
                ++c;
                q[cur_k] = 1;
                printf("%3d" , cur_k+1);
            } else {
                c += 2;
                q[cur_k] = 1;
                q[cur_m] = 1;
                printf("%3d%3d" , cur_k+1, cur_m+1);
            }
        }
        cout << endl;
    }
    return 0;
}

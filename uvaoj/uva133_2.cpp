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
#define repr(e, i) for (auto e : i)
#define all(x) x.begin(), x.end()
#define pii pair<int, int>

using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 33;
const long long MOD = 1000000007;
const int DIRX[] = {1, 0, -1, 0};
const int DIRY[] = {0, 1, 0, -1};
typedef long long ll;

int main() {
#ifdef AZUKI_LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, k, m;
    while (cin >> n >> k >> m) {
        if (n == 0) break;
        vector<int> q(n, 1);
        int cnt = n;
        int p1 = -1, p2 = n;
        int step = 0;
        while (cnt) {
            step = 0;
            while (step < k) {
                p1 = (p1 + 1) % n;
                if (q[p1]) {
                    ++step;
                }
            }
            step = 0;
            while (step < m) {
                p2 = (p2 + (n - 1)) % n;
                if (q[p2]) {
                    ++step;
                }
            }
            if (p1 == p2) {
                --cnt;
                printf("%3d", p1 + 1);
                q[p1] = 0;
            } else {
                cnt -= 2;
                printf("%3d%3d", p1 + 1, p2 + 1);
                q[p1] = 0;
                q[p2] = 0;
            }
            if(cnt) printf(",");
        }
        printf("\n");
    }
    return 0;
}
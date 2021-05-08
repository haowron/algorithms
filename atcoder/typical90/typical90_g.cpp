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

// https://atcoder.jp/contests/typical90/tasks/typical90_g


using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 33;
typedef long long ll;
const long long mod = 1000000007;


int main() {
#ifdef AZUKI_LOCAL
    freopen("../input.txt", "r", stdin);
    //freopen("../output.txt", "w", stdout);
#endif
    int n, q, t, t1, t2;
    set<int> classes;
    while (cin >> n) {
        classes.clear();
        rep(i, n) {
            scanf("%d", &t);
            classes.insert(t);
        }
        scanf("%d", &q);
        rep(i, q) {
            scanf("%d", &t);
            auto p = classes.upper_bound(t);
            t1 = *p;
            if (p == classes.begin()) printf("%d\n", abs(t - t1));
            else if (p == classes.end()) {
                --p;
                t2 = *p;
                printf("%d\n", abs(t - t2));
            } else {
                --p;
                t2 = *p;
                printf("%d\n", min(abs(t - t1), abs(t - t2)));
            }
        }
    }
    return 0;
}

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

// https://atcoder.jp/contests/typical90/tasks/typical90_f


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
    int n, k;
    string s;
    while (cin >> n >> k >> s) {
        char ans[k + 1];
        int left = 0;
        rep(p, k) {
            char c = 'z';
            for (int i = left; i <= n + p - k; ++i) {
                if (c > s[i]) {
                    c = s[i];
                    left = i + 1;
                }
            }
            ans[p] = c;
        }
        ans[k] = '\0';
        printf("%s\n", ans);
    }
    return 0;
}

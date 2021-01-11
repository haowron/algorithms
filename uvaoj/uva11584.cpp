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


using namespace std;
const int maxn = 1001;
const int inf = 0x3f3f3f3f;
typedef long long ll;

int G[1001][1001];
int ans[1001];

int main() {
#ifdef AZUKI_LOCAL
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int kase;
    scanf("%d", &kase);
    while (kase--) {
        string s;
        cin >> s;

        memset(G, 0, sizeof(G));
        memset(ans, 0x3f, sizeof(ans));
        rep(i, s.size() * 2 - 1) {
            int l = i / 2, r = i - l;
            while (l >= 0 && r < s.size()) {
                if (s[l] != s[r]) break;
                G[l][r] = 1;
                --l;
                ++r;
            }
        }

        rep(i, s.size()) {
            rep(j, i + 1) {
                if (G[j][i]) {
                    if (j == 0) ans[i] = 1;
                    else ans[i] = min(ans[i], ans[j - 1] + 1);
                }
            }
        }
        printf("%d\n", ans[s.size() - 1]);
    }
    return 0;
}
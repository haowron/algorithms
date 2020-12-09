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
const int maxn = 80 + 5;
const int inf = 0x3f3f3f3f;
typedef long long ll;


char s[maxn];
int m, n, cnt;

bool dfs(int idx) {
    rep(i, n) {
        bool ok = true;
        s[idx] = 'A' + i;
        for (int j = 1; j < idx / 2 + 2; ++j) {
            if (!memcmp(s - j + idx + 1, s - j * 2 + idx + 1, sizeof(char) * j)) {
                ok = false;
                break;
            }
        }
        if (ok) {
            ++cnt;
            if (cnt == m) return true;
            if (dfs(idx + 1)) return true;
        }
    }
    s[idx] = 0;
    return false;
}

int main() {
#ifdef AZUKI_LOCAL
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    while (cin >> m >> n) {
        if (!m) return 0;
        memset(s, 0, sizeof(s));
        cnt = 0;
        dfs(0);
        int sz = 0;
        while (s[sz + 1]) {
            printf("%c", s[sz]);
            ++sz;
            if (sz!=64 && !(sz % 4)) printf(" ");
            if (!(sz % 64)) printf("\n");
        }
        printf("%c\n%d\n", s[sz], sz + 1);
    }

}

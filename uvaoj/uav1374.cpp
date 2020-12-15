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
const int maxn = 14;
const int inf = 0x3f3f3f3f;
typedef long long ll;


int answers[maxn];
int cnt;

bool dfs(int d, int maxd) {
    if (answers[d] == cnt) return true;
    if (d == maxd) return false;
    int maxv = answers[0];
    rep(i, d) maxv = max(maxv, answers[i + 1]);
    if ((maxv << (maxd - d)) < cnt) return false;
    for (int i = d; i >= 0; --i) {
        answers[d + 1] = answers[d] + answers[i];
        if (dfs(d + 1, maxd)) return true;
        answers[d + 1] = answers[d] - answers[i];
        if (dfs(d + 1, maxd)) return true;
    }
    return false;
}


int solve() {
    if (cnt == 1) return 0;
    answers[0] = 1;
    rep(maxd, maxn) {
        if (dfs(0, maxd)) return maxd;
    }
    return maxn;
}

int main() {
#ifdef AZUKI_LOCAL
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif

    while (cin >> cnt) {
        if(!cnt) return 0;
        cout << solve() << endl;
    }
}

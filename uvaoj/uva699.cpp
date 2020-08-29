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
const int MAXN = 10e4 + 5;
const int INF = 0x3f3f3f3f;
typedef long long ll;

int ans[200];
int start_idx, end_idx, offset = 100;

void solve(int cur_idx) {
    int data;
    cin >> data;
    if (data == -1) return;
    ans[offset + cur_idx] += data;
    solve(cur_idx - 1);
    solve(cur_idx + 1);
    start_idx = min(start_idx, cur_idx - 1);
    end_idx = max(end_idx, cur_idx + 1);
}


int main() {
#ifdef AZUKI_LOCAL
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int kase = 0;
    while (true) {
        memset(ans, 0, sizeof(ans));
        start_idx = 200, end_idx = -1;
        solve(0);
        if (start_idx == 200) break;
        printf("Case %d:\n", ++kase);
        for (int i = start_idx + 1; i < end_idx - 1; ++i) {
            cout << ans[i + offset] << " ";
        }
        cout << ans[end_idx + offset - 1] << endl << endl;
    }
    return 0;
}

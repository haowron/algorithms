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
#define repr(e, i) for (auto& e : i)
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define max(a, b) a > b ? a : b;
#define min(a, b) a < b ? a : b;

using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 33;
const long long MOD = 1000000007;
const int DIRX[] = {1, 0, -1, 0, 1, 1, -1, -1, 0};
const int DIRY[] = {0, 1, 0, -1, 1, -1, 1, -1, 0};
typedef long long ll;

void solve(string& original_str) {
    int length = original_str.size();
    vector<int> next(length + 1, -1);
    int cur = length, tail = length;
    rep(i, length) {
        if (original_str[i] == '[') {
            cur = length;
        } else if (original_str[i] == ']') {
            cur = tail;
        } else {
            if (cur == tail) {
                tail = i;
            }
            next[i] = next[cur];
            next[cur] = i;
            cur = i;
        }
    }
    int p = length;
    string ans;
    while (p!=tail) {
        p = next[p];
        ans += original_str[p];
    }
    cout << ans << endl;
}

int main() {
#ifdef AZUKI_LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    string original_str;
    while (cin >> original_str) {
        solve(original_str);
    }
    return 0;
}

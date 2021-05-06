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
const int inf = 0x3f3f3f3f;
const int maxn = 1000;
typedef long long ll;

// https://atcoder.jp/contests/typical90/tasks/typical90_b

int n;
vector<string> ans;

void solve(const string& cur, int left_cnt) {
    if (cur.size() == n) {
        if (left_cnt == 0) ans.push_back(cur);
        return;
    }
    solve(cur + '(', left_cnt + 1);
    if (left_cnt) {
        string cur2 = cur + ')';
        solve(cur2, left_cnt - 1);
    }

}

int main() {
#ifdef AZUKI_LOCAL
    freopen("../input.txt", "r", stdin);
    //freopen("../output.txt", "w", stdout);
#endif
    while (cin >> n) {
        if (n % 2) {
            cout << endl;
            continue;
        }
        ans.clear();
        solve("", 0);
        //sort(all(ans));
        for (const string &x: ans) cout << x << endl;
    }

    return 0;
}

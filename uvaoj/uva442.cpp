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
const int MAXN = 10e4;
const int INF = 0x3f3f3f3f;
typedef long long ll;


int main() {
#ifdef AZUKI_LOCAL
    freopen("../input.txt", "r", stdin);
    //freopen("../output.txt", "w", stdout);
#endif
    int kase, x, y, ans;
    char c;
    cin >> kase;
    map<char, pair<int, int> > m;
    while (kase--) {
        cin >> c >> x >> y;
        m[c] = {x, y};
    }
    string expr;
    while (cin >> expr) {
        ans = 0;
        stack<pair<int, int> > stk;
        bool has_ans = true;
        for (auto cc: expr) {
            if (cc == ')') {
                pair<int, int> left, right;
                right = stk.top();
                stk.pop();
                left = stk.top();
                stk.pop();
                if (left.second != right.first) {
                    has_ans = false;
                    break;
                }
                ans += left.first * left.second * right.second;
                left.second = right.second;
                stk.push(left);
            } else if (cc == '(') {
                continue;
            } else {
                stk.push(m[cc]);
            }
        }
        if (has_ans)cout << ans << endl;
        else cout << "error" << endl;
    }
    return 0;
}

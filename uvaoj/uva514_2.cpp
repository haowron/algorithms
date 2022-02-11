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

void check(vector<int>& t_order) {
    stack<int> stk;
    int length = t_order.size();
    int idx = 0;
    for (int i = 1; i <= length; ++i) {
        while (!stk.empty() && stk.top() == t_order[idx]) {
            stk.pop();
            ++idx;
        }
        stk.push(i);
    }
    while (!stk.empty() && stk.top() == t_order[idx]) {
        stk.pop();
        ++idx;
    }
    if (idx == length) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
}

int main() {
#ifdef AZUKI_LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t_count;
    while (cin >> t_count) {
        if (!t_count) break;
        int t;
        while (cin >> t) {
            if (!t) break;
            vector<int> t_order;
            t_order.push_back(t);
            rep(i, t_count - 1) {
                cin >> t;
                t_order.push_back(t);
            }
            check(t_order);
        }
        printf("\n");
    }
    return 0;
}

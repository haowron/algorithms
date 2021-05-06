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

// https://atcoder.jp/contests/typical90/tasks/typical90_a

int k, n, l;

bool check(vector<int> &a, int target) {
    int num = 0;
    int cur = 0;
    for (int i = 0; i <= a.size(); ++i) {
        if (a[i] - cur >= target && l - a[i] >= target) {
            cur = a[i];
            num += 1;
        }
    }
    if (num >= k) return false;
    return true;
}


int solve(vector<int> &a) {
    int left = 0, right = 1000000001;
    while (left < right - 1) {
        int middle = (right + left) / 2;
        if (check(a, middle)) right = middle;
        else left = middle;
    }
    return left;
}

int main() {
#ifdef AZUKI_LOCAL
    freopen("../input.txt", "r", stdin);
    //freopen("../output2.txt", "w", stdout);
#endif
    while (cin >> n >> l >> k) {
        vector<int> a(n+1);
        rep(i, n) cin >> a[i+1];
        cout << solve(a) << endl;
    }

    return 0;
}

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

#define rep(i, n) for (int i = 0; i < n; ++i)
#define all(x) x.begin(), x.end()


using namespace std;
const int MAXN = 10e5 + 5;
const int INF = 0x7f7f7f7f;
typedef long long ll;


int main() {
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    //freopen("../output.txt", "w", stdout);
#endif
    int cse, l, cnt;
    cin >> cse;

    while (cse--) {
        cin >> l >> cnt;
        float half_l = l / 2.0;
        vector<int> x(cnt);
        rep(i, cnt) {
            cin >> x[i];
        }
        int min_ans = 0, max_ans = 0;
        for (auto i:x) {
            if (i <= half_l) {
                min_ans = max(i, min_ans);
                max_ans = max(max_ans, l - i);
            } else {
                min_ans = max(l - i, min_ans);
                max_ans = max(max_ans, i);
            }
        }
        cout << min_ans << " " << max_ans << endl;
    }
    return 0;
}

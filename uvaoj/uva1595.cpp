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
#include <unordered_map>

#define rep(i, n) for (int i = 0; i < n; ++i)
#define repr(e, i) for (auto e: i)
#define all(x) x.begin(), x.end()


using namespace std;
const int MAXN = 10e4;
const int INF = 0x3f3f3f3f;
typedef long long ll;


double l;

int cmp(pair<int, int> a, pair<int, int> b) {
    return a.first < b.first || (a.first == b.first && ((a.second < b.second) ^ (a.first < l)));
}


int main() {
#ifdef AZUKI_LOCAL
    freopen("../input.txt", "r", stdin);
    //freopen("../output.txt", "w", stdout);
#endif
    int t, n;
    int x, y;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<pair<int, int> > points(n);
        l = 0;
        rep(i, n) {
            cin >> x >> y;
            points[i] = {x, y};
            l += x;
        }
        l = l / n;
        sort(all(points), cmp);
        // 这个地方如果用l*2做会有精度问题，导致wa
        int l2 = points[0].first + points[n-1].first;
        bool ok = true;
        rep(i, n / 2 + 1) {
            if (points[i].first * 2 == l2) break;
            if ((points[i].first + points[n - i - 1].first != l2) || (points[i].second != points[n - i - 1].second)) {
                ok = false;
                break;
            }
        }
        cout << (ok ? "YES" : "NO") << endl;
    }
    return 0;
}

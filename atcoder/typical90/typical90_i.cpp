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

// https://atcoder.jp/contests/typical90/tasks/typical90_i


using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 33;
typedef long long ll;
const long long mod = 1000000007;

double calc_angle(const pair<double, double> &p, const pair<double, double> &p2) {
    double rtn;
    if (p2.first == p.first) {
        if (p2.second > p.second) return 90.0;
        return 270;
    } else rtn = atan((p2.second - p.second) / double(p2.first - p.first)) / 3.14159265358979 * 180.0;
    if (p2.first < p.first) rtn += 180.0;
    return rtn > 0 ? rtn : rtn + 360;
}


int main() {
#ifdef AZUKI_LOCAL
    freopen("../input.txt", "r", stdin);
    //freopen("../output.txt", "w", stdout);
#endif

    double n, x, y;
    while (cin >> n) {
        double ans = 0;
        vector<pair<double, double>> points(n);
        rep(i, n) {
            cin >> x >> y;
            points[i] = {x, y};
        }
        for (auto p: points) {
            set<double> angles;
            for (auto p2: points) {
                if (p == p2) continue;
                double angle = calc_angle(p, p2);
                angles.insert(angle);
                angles.insert(angle + 360);
            }
            for (auto angle: angles) {
                if (angle >= 360) break;
                auto oppo_angle_p = angles.lower_bound(angle + 180);
                double angle1 = *oppo_angle_p;
                --oppo_angle_p;
                double angle2 = *oppo_angle_p;
                while (angle1 - angle >= 360) angle1 -= 360;
                while (angle2 - angle >= 360) angle2 -= 360;
                angle1 = min(abs(angle1 - angle), 360 - abs(angle1 - angle));
                angle2 = min(abs(angle2 - angle), 360 - abs(angle2 - angle));
                ans = max(ans, angle1);
                ans = max(ans, angle2);
            }
        }
        printf("%.12lf\n", ans);
    }
    return 0;
}

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
#define repr(e, i) for (auto e : i)
#define all(x) x.begin(), x.end()
#define pii pair<int, int>

using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 33;
const long long MOD = 1000000007;
const int DIRX[] = {1, 0, -1, 0};
const int DIRY[] = {0, 1, 0, -1};
typedef long long ll;
int main() {
#ifdef AZUKI_LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int _round;
    while (cin >> _round) {
        if (_round == -1) break;
        string s1, s2;
        cin >> s1 >> s2;
        int failed_times = 0;
        map<char, bool> G;

        bool finished = true;
        repr(e, s1) G[e] = false;
        repr(e, s2) {
            finished = true;
            if (G.find(e) == G.end()) {
                ++failed_times;
                G[e] = true;
            } else
                G[e] = true;
            repr(e, G) {
                if (!e.second) {
                    finished = false;
                    break;
                }
            }
            if (finished) break;
        }

        if (failed_times > 6) {
            printf("Round %d\nYou lose.\n", _round);
        } else if (finished) {
            printf("Round %d\nYou win.\n", _round);
        } else {
            printf("Round %d\nYou chickened out.\n", _round);
        }
    }
    return 0;
}
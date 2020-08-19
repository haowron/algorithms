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
const int MAXN = 10e5 + 5;
const int INF = 0x7f7f7f7f;
typedef long long ll;
int h[12][12];
int v[12][12];

// s means size of blocks
bool check(int x, int y, int s) {
    rep(i, s) {
        if (!h[x][y + i]) return false;
        if (!v[x + i][y]) return false;
        if (!h[x + s][y + i]) return false;
        if (!v[x + i][y + s]) return false;
    }
    return true;
}

int main() {
#ifndef ONLINE_JUDGE
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);
#endif
    string s;
    // 上，前，左，右，后，下
    int tables[24][6] = {
            {1, 2, 3, 4, 5, 6},
            {1, 3, 5, 2, 4, 6},
            {1, 4, 2, 5, 3, 6},
            {1, 5, 4, 3, 2, 6},

            {2, 1, 4, 3, 6, 5},
            {2, 3, 1, 6, 4, 5},
            {2, 4, 6, 1, 3, 5},
            {2, 6, 3, 4, 1, 5},

            {3, 1, 2, 5, 6, 4},
            {3, 2, 6, 1, 5, 4},
            {3, 5, 1, 6, 2, 4},
            {3, 6, 5, 2, 1, 4},

            {4, 1, 5, 2, 6, 3},
            {4, 2, 1, 6, 5, 3},
            {4, 5, 6, 1, 2, 3},
            {4, 6, 2, 5, 1, 3},

            {5, 1, 3, 4, 6, 2},
            {5, 3, 6, 1, 4, 2},
            {5, 4, 1, 6, 3, 2},
            {5, 6, 4, 3, 1, 2},

            {6, 2, 4, 3, 5, 1},
            {6, 3, 2, 5, 4, 1},
            {6, 4, 5, 2, 3, 1},
            {6, 5, 3, 4, 2, 1},

    };
    while (cin >> s) {
        bool ans;
        rep(i, 24) {
            ans = true;
            rep(j, 6) {
                if (s[j] != s[tables[i][j] + 5]) {
                    ans = false;
                    break;
                }
            }
            if (ans) break;
        }
        cout << (ans ? "TRUE" : "FALSE") << endl;
    }
    return 0;
}

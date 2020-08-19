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


int main() {
#ifndef ONLINE_JUDGE
    //freopen("../input.txt", "r", stdin);
    //freopen("../output.txt", "w", stdout);
#endif
    string s1, s2;
    bool f;
    int s1tb[200];
    int s2tb[200];

    while (cin >> s1 >> s2) {
        f = true;
        memset(s1tb, 0, sizeof(s1tb));
        memset(s2tb, 0, sizeof(s2tb));
        rep(i, s1.size()) {
            ++s1tb[s1[i]];
            ++s2tb[s2[i]];
        }
        sort(s1tb, s1tb + 200);
        sort(s2tb, s2tb + 200);
        rep(i, 200) {
            if (s1tb[i] != s2tb[i]) {
                f = false;
                break;
            }
        }
        if (f) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}

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
const int maxn = 100000 + 5;
const int inf = 0x3f3f3f3f;
typedef long long ll;


int main() {
#ifdef AZUKI_LOCAL
    freopen("../input.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
    int height;
    char floor_str[5];
    string query;
    int kase = 1;
    while (cin >> height) {
        if (!height) break;
        if(kase > 1) {
            cout << endl;
        }
        printf("S-Tree #%d:\n", kase);
        ++kase;
        int floors[height];
        rep(i, height) {
            scanf("%s", floor_str);
            floors[floor_str[1] - '1'] = height - i - 1;
        }
        string s;
        cin >> s;
        int cnt;
        cin >> cnt;
        while (cnt--) {
            int idx = 0;
            cin >> query;
            rep(i, query.size()) {
                idx += (query[i] - '0') << floors[i];
            }
            cout << s[idx];
        }
        cout << endl;
    }
    return 0;
}

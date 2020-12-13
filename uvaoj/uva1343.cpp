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
const int maxn = 80 + 5;
const int inf = 0x3f3f3f3f;
typedef long long ll;


int check_dir[] = {6, 7, 8, 11, 12, 15, 16, 17};
int reverse_dirs[] = {5, 4, 7, 6, 1, 0, 3, 2};

int dirs[8][7] = {
        0, 2, 6, 11, 15, 20, 22,
        1, 3, 8, 12, 17, 21, 23,
        10, 9, 8, 7, 6, 5, 4,
        19, 18, 17, 16, 15, 14, 13,
        23, 21, 17, 12, 8, 3, 1,
        22, 20, 15, 11, 6, 2, 0,
        13, 14, 15, 16, 17, 18, 19,
        4, 5, 6, 7, 8, 9, 10,
};

char ans;
char ans1[1000];
char input[24];
int max_limit;


bool is_ok() {
    rep(i, 8) if (input[check_dir[i]] != input[6]) return false;
    ans = input[6];
    return true;
}


void rotate(int dir) {
    char c = input[dirs[dir][0]];
    rep(i, 6) input[dirs[dir][i]] = input[dirs[dir][i + 1]];
    input[dirs[dir][6]] = c;
}

void reverse_rotate(int dir) {
    rotate(reverse_dirs[dir]);
}

int h() {
    int x[3];
    int rtn = 0;
    memset(x, 0, sizeof(x));
    rep(i, 8) x[input[check_dir[i]] - '1'] += 1;
    rep(i, 3) rtn = max(rtn, x[i]);
    return 8 - rtn;
}


bool dfs(int limit) {
    if (!limit) return is_ok();
    if (h() > limit) return false;
    rep(i, 8) {
        rotate(i);
        ans1[max_limit - limit] = 'A' + i;
        if (dfs(limit - 1)) return true;
        reverse_rotate(i);
    }
    return false;
}

void solve() {
    max_limit = 0;
    memset(ans1, '\0', sizeof(ans1));
    while (++max_limit) {
        if (dfs(max_limit)) return;
    }
}


int main() {
#ifdef AZUKI_LOCAL
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    char num;
    while (cin >> num) {
        if (num == '0') return 0;
        rep(i, 23) scanf("%s", input + i + 1);
        input[0] = num;
        if (is_ok()) cout << "No moves needed" << endl;
        else {
            solve();
            cout << ans1 << endl;
        }
        cout << ans << endl;
    }
}

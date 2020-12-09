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


int G[26][26];
int alphabets[26];
int ans[8];
int min_ans[8];
int min_d;


int dis(int k, int idx) {
    int d = 0;
    rep(i, idx) {
        if (G[k][ans[i]]) d = max(d, idx - i);
    }
    return d;
}

void dfs(int idx) {
    if (idx == 8) {
        int bds = 0;
        rep(i, 8) {
            int bd = 0;
            rep(j, 8) {
                if (G[ans[i]][ans[j]]) {
                    bd = max(bd, abs(i - j));
                }
            }
            bds = max(bds, bd);
        }
        if (bds < min_d){
            min_d = bds;
            memcpy(min_ans, ans, sizeof(ans));
        }
        return;
    }
    rep(i, 26) {
        if (!alphabets[i]) continue;
        if (dis(i, idx) >= min_d) continue;
        alphabets[i] = 0;
        ans[idx] = i;
        dfs(idx + 1);
        alphabets[i] = 1;
    }
}


int main() {
#ifdef AZUKI_LOCAL
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    string s;

    while (cin >> s) {
        if (s == "#") return 0;
        memset(G, 0, sizeof(G));
        memset(alphabets, 0, sizeof(alphabets));
        min_d = inf;
        bool is_key = true;
        int k;
        repr(e, s) {
            if (e == ':') {
                is_key = false;
            } else if (e == ';') {
                is_key = true;
            } else {
                if (is_key) {
                    k = e - 'A';
                } else {
                    G[k][e - 'A'] = 1;
                    G[e - 'A'][k] = 1;
                    alphabets[k] = 1;
                    alphabets[e - 'A'] = 1;
                }
            }
        }
        dfs(0);
        rep(i,7){
            printf("%c ", min_ans[i] + 'A');
        }
        printf("%c -> %d\n", min_ans[7] + 'A', min_d);
    }

}

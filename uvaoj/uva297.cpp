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
const int MAXN = 35;
const int INF = 0x3f3f3f3f;
typedef long long ll;

int blocks[MAXN][MAXN];


void draw(string &t, int &idx, int x, int y, int block_size) {
    char c = t[idx];
    ++idx;
    if (c == 'f') {
        for (int i = 0; i < block_size; ++i) {
            for (int j = 0; j < block_size; ++j) {
                blocks[x + i][y + j] = 1;
            }
        }
    } else if (c == 'p') {
        int new_block_size = block_size / 2;
        draw(t, idx, x + new_block_size, y, new_block_size);
        draw(t, idx, x, y, new_block_size);
        draw(t, idx, x, y + new_block_size, new_block_size);
        draw(t, idx, x + new_block_size, y + new_block_size, new_block_size);
    }
}

int main() {
#ifdef AZUKI_LOCAL
    freopen("../input.txt", "r", stdin);
    //freopen("../output.txt", "w", stdout);
#endif
    int kase;
    cin >> kase;
    while (kase--) {
        string t1, t2;
        cin >> t1 >> t2;
        memset(blocks, 0, sizeof(blocks));
        int idx1 = 0, idx2 = 0;
        int ans = 0;
        draw(t1, idx1, 0, 0, 32);
        draw(t2, idx2, 0, 0, 32);
        ans = 0;
        for (int i = 0; i < MAXN; ++i) {
            for (int j = 0; j < MAXN; ++j) {
                ans += blocks[i][j];
            }
        }
        printf("There are %d black pixels.\n", ans);
    }
    return 0;
}

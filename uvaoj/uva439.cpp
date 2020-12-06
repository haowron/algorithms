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
#define pii pair<int, int>


using namespace std;
const int maxn = 100000 + 5;
const int inf = 0x3f3f3f3f;
typedef long long ll;

const pii DIR[] = {
        {1,  2},
        {1,  -2},
        {-1, 2},
        {-1, -2},
        {2,  1},
        {2,  -1},
        {-2, 1},
        {-2, -1}
};


int main() {
#ifdef AZUKI_LOCAL
    freopen("../input.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
    char start[3], end[3];
    int x0, y0, x1, y1, G[8][8];
    while (scanf("%s%s", &start, &end) != EOF) {
        x0 = start[0] - 'a';
        y0 = start[1] - '1';
        x1 = end[0] - 'a';
        y1 = end[1] - '1';
        memset(G, 0, sizeof(G));
        queue<pii > q;
        q.push({x0, y0});
        G[x0][y0] = 1;
        while (!q.empty()) {
            pii u = q.front();
            int cur = G[u.first][u.second] + 1;
            if (u.first == x1 && u.second == y1) {
                printf("To get from %s to %s takes %d knight moves.\n", start, end, cur - 2);
                break;
            }
            q.pop();
            repr(e, DIR) {
                pii v = {u.first + e.first, u.second + e.second};
                if (v.first >= 0 && v.first < 8 && v.second >= 0 && v.second < 8 && !G[v.first][v.second]) {
                    G[v.first][v.second] = cur;
                    q.push(v);
                }
            }
        }
    }
    return 0;
}

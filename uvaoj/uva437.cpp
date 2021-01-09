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
const int maxn = 14;
const int inf = 0x3f3f3f3f;
typedef long long ll;

map<pii, int> G;
int rotations[6][3] = {
        {0, 1, 2},
        {1, 0, 2},
        {0, 2, 1},
        {2, 0, 1},
        {1, 2, 0},
        {2, 1, 0}
};

int solve(const vector<vector<int>> &boxes, int box_index, int rotation) {
    if (G.find({box_index, rotation}) != G.end()) return G[{box_index, rotation}];
    int ans = 0;
    int x = boxes[box_index][rotations[rotation][0]], y = boxes[box_index][rotations[rotation][1]], z = boxes[box_index][rotations[rotation][2]];
    rep(i, boxes.size()) {
        rep(j, 6) {
            int x2 = boxes[i][rotations[j][0]], y2 = boxes[i][rotations[j][1]];
            if (x2 < x && y2 < y) ans = max(solve(boxes, i, j), ans);
        }
    }
    G[{box_index, rotation}] = ans + z;
    return ans + z;
}


int main() {
#ifdef AZUKI_LOCAL
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int kase = 0, n;
    while (scanf("%d", &n) && n) {
        vector<vector<int> > boxes(n, vector<int>(3));
        rep(i, n) scanf("%d%d%d", &boxes[i][0], &boxes[i][1], &boxes[i][2]);
        G.clear();
        int ans = 0;
        rep(i, boxes.size()) {
            rep(j, 6) {
                ans = max(solve(boxes, i, j), ans);
            }
        }
        printf("Case %d: maximum height = %d\n", ++kase, ans);
    }

    return 0;
}

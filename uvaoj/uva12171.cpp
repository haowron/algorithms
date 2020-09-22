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
const int maxn = 105;
const int inf = 0x3f3f3f3f;
typedef long long ll;

int areas[105][105][105];
typedef struct {
    int x, y, z;
} xyz;

typedef struct {
    int x1, y1, z1, x0, y0, z0;
} block;
int block_count;

vector<block> blocks;
vector<int> xs, ys, zs;
int dx[] = {1, -1, 0, 0, 0, 0};
int dy[] = {0, 0, 1, -1, 0, 0};
int dz[] = {0, 0, 0, 0, 1, -1};

void init() {
    blocks.clear();
    xs.clear();
    ys.clear();
    zs.clear();
    xs.push_back(0);
    ys.push_back(0);
    zs.push_back(0);
    memset(areas, 0, sizeof(areas));
}

int find_x(int &ele, vector<int> &v) {
    return find(all(v), ele) - v.begin();
}


void color_areas() {
    repr(e, blocks) {
        for (int i = find_x(e.x0, xs); i < find_x(e.x1, xs); ++i) {
            for (int j = find_x(e.y0, ys); j < find_x(e.y1, ys); ++j) {
                for (int k = find_x(e.z0, zs); k < find_x(e.z1, zs); ++k) {
                    areas[i][j][k] = 1;
                }
            }
        }
    }
}

bool is_valid(xyz &p) {
    return p.x >= 0 && p.x < xs.size() -1 && p.y >= 0 && p.y < ys.size()-1 && p.z >= 0 && p.z < zs.size()-1 &&
           areas[p.x][p.y][p.z] != 2;
}

void solve() {
    int ans1 = 0, ans2 = xs[1] * ys[1] * zs[1];
    xyz p;
    queue<xyz> q;
    p.x = 0;
    p.y = 0;
    p.z = 0;
    q.push(p);
    areas[0][0][0] = 2;
    while (!q.empty()) {
        xyz u = q.front();
        q.pop();
        rep(i, 6) {
            xyz v = u;
            v.x = v.x + dx[i];
            v.y = v.y + dy[i];
            v.z = v.z + dz[i];
            if (!is_valid(v)) continue;
            if (areas[v.x][v.y][v.z]) {
                if (i < 2) {
                    ans1 += (ys[v.y + 1] - ys[v.y]) * (zs[v.z + 1] - zs[v.z]);
                } else if (i < 4) {
                    ans1 += (xs[v.x + 1] - xs[v.x]) * (zs[v.z + 1] - zs[v.z]);
                } else {
                    ans1 += (xs[v.x + 1] - xs[v.x]) * (ys[v.y + 1] - ys[v.y]);
                }
            } else {
                ans2 += (xs[v.x + 1] - xs[v.x]) * (ys[v.y + 1] - ys[v.y]) * (zs[v.z + 1] - zs[v.z]);
                areas[v.x][v.y][v.z] = 2;
                q.push(v);
            }

        }
    }
    cout << ans1 << " " << (xs[xs.size() - 1] * ys[ys.size() - 1] * zs[zs.size() - 1] - ans2) << endl;
}

int main() {
#ifdef AZUKI_LOCAL
    freopen("../input.txt", "r", stdin);
    //freopen("../output.txt", "w", stdout);
#endif
    int kase;
    cin >> kase;
    while (kase--) {
        init();
        cin >> block_count;
        rep(i, block_count) {
            block b;
            cin >> b.x0 >> b.y0 >> b.z0 >> b.x1 >> b.y1 >> b.z1;
            b.x1 += b.x0;
            b.y1 += b.y0;
            b.z1 += b.z0;

            xs.push_back(b.x1);
            ys.push_back(b.y1);
            zs.push_back(b.z1);
            xs.push_back(b.x0);
            ys.push_back(b.y0);
            zs.push_back(b.z0);
            blocks.push_back(b);
        }
        sort(all(xs));
        xs.erase(unique(all(xs)), xs.end());
        sort(all(ys));
        ys.erase(unique(all(ys)), ys.end());
        sort(all(zs));
        zs.erase(unique(all(zs)), zs.end());
        xs.push_back(xs[xs.size() - 1] + 1);
        ys.push_back(ys[ys.size() - 1] + 1);
        zs.push_back(zs[zs.size() - 1] + 1);
        color_areas();
        solve();
    }
    return 0;
}

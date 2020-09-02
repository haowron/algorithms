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
const int maxn = 12;
const int inf = 0x3f3f3f3f;
typedef long long ll;

int start_x, start_y, finish_x, finish_y, dir;


struct node {
    int x, y, d;

    node(int x = 0, int y = 0, int d = 0) : x(x), y(y), d(d) {}
};

int edges[maxn][maxn][4][3];
int dis[maxn][maxn][4];
node path[maxn][maxn][4];

map<char, int> flr;
map<char, int> nesw;

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
const int dirs[] = {0, 3, 1};

void init_program() {
    flr['F'] = 0;
    flr['L'] = 1;
    flr['R'] = 2;
    nesw['N'] = 0;
    nesw['E'] = 1;
    nesw['S'] = 2;
    nesw['W'] = 3;
}


void init() {
    memset(edges, 0, sizeof(edges));
    memset(dis, -1, sizeof(dis));
    memset(path, 0, sizeof(path));
}


void print_ans(node n) {
    stack<node> stk;
    while (true) {
        stk.push(n);
        if (!dis[n.x][n.y][n.d]) break;
        n = path[n.x][n.y][n.d];
    }
    stk.push(node(start_x, start_y, dir));
    int idx = 0;
    while (!stk.empty()) {
        if (idx % 10 == 0) printf(" ");
        printf(" (%d,%d)", stk.top().x, stk.top().y);
        ++idx;
        if (idx % 10 == 0) printf("\n");
        stk.pop();
    }
    if(idx % 10 != 0) printf("\n");
}

bool inside(int x, int y) {
    return x >= 1 && x <= 9 && y >= 1 && y <= 9;
}

void solve() {
    queue<node> q;
    node u(start_x + dx[dir], start_y + dy[dir], dir);
    dis[start_x + dx[dir]][start_y + dy[dir]][dir] = 0;
    q.push(u);
    while (!q.empty()) {
        u = q.front();
        q.pop();
        if (u.x == finish_x && u.y == finish_y) {
            print_ans(u);
            return;
        }
        rep(i, 3) {
            node v(u.x + dx[(u.d + dirs[i]) % 4], u.y + dy[(u.d + dirs[i]) % 4], (u.d + dirs[i]) % 4);
            if (edges[u.x][u.y][u.d][i] && dis[v.x][v.y][v.d] < 0 && inside(v.x, v.y)) {
                dis[v.x][v.y][v.d] = dis[u.x][u.y][u.d] + 1;
                path[v.x][v.y][v.d] = u;
                q.push(v);
            }
        }
    }
    cout << "  No Solution Possible" << endl;
}

int main() {
#ifdef AZUKI_LOCAL
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    init_program();
    string map_name, s;
    char dir_str;
    while (getline(cin, map_name)) {
        if (map_name == "END") break;
        init();

        getline(cin, s);
        stringstream ss(s);
        ss >> start_x >> start_y >> dir_str >> finish_x >> finish_y;
        dir = nesw[dir_str];

        while (getline(cin, s)) {
            if (s == "0") break;
            int x, y;
            string ee;
            stringstream ss2(s);
            ss2 >> x >> y;
            while (ss2 >> ee) {
                if (ee == "*") break;
                for (int i = 1; i < ee.size(); ++i) {
                    edges[x][y][nesw[ee[0]]][flr[ee[i]]] = 1;
                }
            }
        }
        cout << map_name << endl;
        solve();
    }
    return 0;
}

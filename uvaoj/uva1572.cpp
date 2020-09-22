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

int G[55][55];
int visited[55];

bool has_node(int i){
    bool has_node = false;
    rep(j, 55){
        if (G[i][j]) {
            has_node = true;
            break;
        }
    }
    return has_node;
}

bool dfs(int u){
    visited[u] = -1;
    rep(v, 55){
        if (!G[u][v]) continue;
        if (visited[v] == -1) return true;
        if (!visited[v] && dfs(v)) return true;
    }
    visited[u] = 1;
    return false;
}

bool topo(){
    stack<int> stk;
    memset(visited, 0 ,sizeof(visited));
    rep(i, 55){
        if(visited[i] || !has_node(i)) continue;
        if (dfs(i)) return true;
    }
    return false;
}

int main() {
#ifdef AZUKI_LOCAL
    freopen("../input.txt", "r", stdin);
    //freopen("../output.txt", "w", stdout);
#endif
    int cube_num;
    char s[9];
    while (cin >> cube_num) {
        memset(G, 0, sizeof(G));
        rep(i_, cube_num){
            scanf("%s", &s);
            for (int i = 0; i < 8; i += 2) {
                if (s[i] == '0') continue;
                for (int j = 0; j < 8; j += 2) {
                    if (i == j || s[j] == '0') continue;
                    int x = s[i] - 'A';
                    x += s[i + 1] == '+' ? 26 : 0;
                    int y = s[j] - 'A';
                    y += s[j + 1] == '-' ? 26 : 0;
                    G[x][y] = 1;
                }
            }
        }
        if(topo()){
            cout << "unbounded" << endl;
        } else {
            cout << "bounded" << endl;
        }
    }
    return 0;
}

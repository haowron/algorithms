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


int main() {
#ifdef AZUKI_LOCAL
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int target;
    int kase = 0;
    while (cin >> target) {
        bool has_ans = false;
        if (!target) return 0;
        int visited[10];
        if (kase++) printf("\n");

        memset(visited, 0, sizeof(visited));
        rep(a, 10) {
            int a1 = a * 10000;
            if (a1 * target > 99999) continue;
            visited[a] = 1;
            rep(b, 10) {
                if (visited[b] == 1) continue;
                int b1 = a1 + b * 1000;
                if (b1 * target > 99999) continue;
                visited[b] = 1;
                rep(c, 10) {
                    if (visited[c] == 1) continue;
                    int c1 = b1 + c * 100;
                    if (c1 * target > 99999) continue;
                    visited[c] = 1;
                    rep(d, 10) {
                        if (visited[d] == 1) continue;
                        int d1 = c1 + d * 10;
                        if (d1 * target > 99999) continue;
                        visited[d] = 1;
                        rep(e, 10) {
                            if (visited[e] == 1) continue;
                            int e1 = d1 + e;
                            int f = target * e1;
                            int f1 = target * e1;
                            if (f > 99999 || f < 10000) continue;
                            visited[e] = 1;
                            while (f) {
                                int g = f % 10;
                                if (visited[g] == 1 || visited[g] == f1)break;
                                visited[g] = f1;
                                f = f / 10;
                            }
                            if (!f) {
                                has_ans = true;
                                printf("%05d / %05d = %d\n", f1, e1, target);
                            }
                            visited[e] = 0;
                        }
                        visited[d] = 0;
                    }
                    visited[c] = 0;
                }
                visited[b] = 0;
            }
            visited[a] = 0;
        }
        if (!has_ans) printf("There are no solutions for %d.\n", target);
    }
    return 0;
}

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
const int MAXN = 10e5 + 5;
const int INF = 0x7f7f7f7f;
typedef long long ll;
int h[12][12];
int v[12][12];

// s means size of blocks
bool check(int x, int y, int s) {
    rep(i, s) {
        if (!h[x][y+i]) return false;
        if (!v[x+i][y]) return false;
        if (!h[x + s][y + i]) return false;
        if (!v[x+i][y + s]) return false;
    }
    return true;
}

// 格式化输入与输出
int main() {
#ifndef ONLINE_JUDGE
    //freopen("../input.txt", "r", stdin);
    //freopen("../output.txt", "w", stdout);
#endif
    int n, c, pnum = 0;
    char hv;
    int x, y;
    while (cin >> c) {
        if(pnum) printf("\n**********************************\n\n");
        ++pnum;
        printf("Problem #%d\n\n", pnum);
        memset(h, 0, sizeof(h));
        memset(v, 0, sizeof(v));
        cin >> n;
        rep(i, n) {
            cin >> hv >> x >> y;
            if (hv == 'H') {
                h[x - 1][y - 1] = 1;
            } else {
                v[y - 1][x - 1] = 1;
            }
        }
        bool block_exist = false;
        for (int i = 1; i <= c; ++i) {
            int block_count = 0;
            rep(j, c - i) {
                rep(k, c - i) {
                    if (check(j, k, i)) ++block_count;
                }
            }

            if (block_count) {
                printf("%d square (s) of size %d\n", block_count, i);
                block_exist = true;
            }
        }
        if (!block_exist) printf("No completed squares can be found.\n");
    }
    return 0;
}

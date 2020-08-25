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
const int MAXN = 10e4 + 5;
const int INF = 0x3f3f3f3f;
typedef long long ll;

int nodes[2][MAXN];
int right_node;

int m, n, num, first_node;

void insert_node(int from, int to) {
    int from_left = nodes[!right_node][from];
    int from_right = nodes[right_node][from];
    int to_left = nodes[!right_node][to];
    if (from_right == to or from == to) return;
    nodes[right_node][from_left] = from_right;
    nodes[!right_node][from_right] = from_left;

    nodes[right_node][to_left] = from;
    nodes[right_node][from] = to;
    nodes[!right_node][to] = from;
    nodes[!right_node][from] = to_left;
}

void swap_node(int from, int to) {

    int from_left = nodes[!right_node][from];
    int from_right = nodes[right_node][from];
    int to_left = nodes[!right_node][to];
    int to_right = nodes[right_node][to];
    if (from_left == to) {
        nodes[right_node][to_left] = from;
        nodes[right_node][from] = to;
        nodes[right_node][to] = from_right;
        nodes[!right_node][from_right] = to;
        nodes[!right_node][to] = from;
        nodes[!right_node][from] = to_left;
    } else if (from_right == to) {
        nodes[right_node][from_left] = to;
        nodes[right_node][to] = from;
        nodes[right_node][from] = to_right;
        nodes[!right_node][to_right] = from;
        nodes[!right_node][from] = to;
        nodes[!right_node][to] = from_left;
    } else {
        nodes[right_node][from_left] = to;
        nodes[right_node][to] = from_right;
        nodes[right_node][to_left] = from;
        nodes[right_node][from] = to_right;

        nodes[!right_node][from_right] = to;
        nodes[!right_node][to] = from_left;
        nodes[!right_node][to_right] = from;
        nodes[!right_node][from] = to_left;
    }
}


int main() {
#ifdef AZUKI_LOCAL
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    string ipt;
    int kase = 0;
    while (getline(cin, ipt)) {
        stringstream ssmn(ipt);
        ssmn >> m >> n;
        // init
        for (int i = 0; i <= m + 1; ++i) {
            nodes[0][i] = i - 1;
            nodes[1][i] = i + 1;
        }
        first_node = 0;
        right_node = 1;
        while (n--) {
            getline(cin, ipt);
            stringstream ss(ipt);
            vector<int> expr;
            while (ss >> num) expr.push_back(num);

            if (expr[0] == 1) {
                insert_node(expr[1], expr[2]);
            } else if (expr[0] == 2) {
                insert_node(expr[1], nodes[right_node][expr[2]]);
            } else if (expr[0] == 3) {
                swap_node(expr[1], expr[2]);
            } else {
                right_node = !right_node;
                first_node = right_node ? 0 : m + 1;

            }
        }
        ll ans = 0;
        bool odd = true;
        int xxx = nodes[right_node][first_node];
        while (xxx <= m && xxx > 0) {
            if (odd) ans += xxx;
            odd = !odd;
            xxx = nodes[right_node][xxx];
        }
        printf("Case %d: %lld\n", ++kase, ans);
    }
    return 0;
}

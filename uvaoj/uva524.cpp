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

int num;
int v[20];


bool check2(int b) {
    return b == 2 || b == 3 || b == 5 || b == 7 || b == 11 || b == 13 || b == 17 || b == 19 || b == 23 || b == 29 ||
           b == 31 || b == 37;
}

bool check(int a, int p) {
    rep(i, p) {
        if (a == v[i]) return false;
    }
    int b = a + v[p - 1];
    if (p != num - 1) return check2(b);
    return check2(b) && check2(a + 1);
}

void push_v(int p) {
    if (p == num) {
        rep(i, num-1) {
            printf("%d ", v[i]);
        }
        printf("%d\n", v[num-1]);
        return;

    }
    for (int i = 2; i < num + 1; ++i) {
        if (check(i, p)) {
            v[p] = i;
            push_v(p + 1);
        }
    }

}


int main() {
#ifdef AZUKI_LOCAL
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int kase = 0;
    while (cin >> num) {
        if (kase) printf("\n");
        printf("Case %d:\n", ++kase);
        v[0] = 1;
        push_v(1);
    }
}

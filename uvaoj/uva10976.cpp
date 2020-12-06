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
    int num;
    while (cin >> num) {
        vector<pii> ans;
        int h = num * 2;
        for (int i = num + 1; i <= h; ++i) {
            int b = i - num;
            if (!((num * i) % b)) ans.emplace_back(num * i / b, i);
        }
        cout << ans.size() << endl;
        repr(e, ans) printf("1/%d = 1/%d + 1/%d\n", num, e.first, e.second);
    }
}

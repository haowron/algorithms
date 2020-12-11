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
#include <unordered_map>


#define rep(i, n) for (int i = 0; i < n; ++i)
#define repr(e, i) for (auto e: i)
#define all(x) x.begin(), x.end()
#define pii pair<int, int>


using namespace std;
const int maxn = 80 + 5;
const int inf = 0x3f3f3f3f;
typedef long long ll;


int len;

bool cut(const int *nums, int d) {
    int h = 0;
    for (int i = 1; i < len; ++i) h += (nums[i] - nums[i - 1] != 1);
    if (!h) return true;
    if (3 * d < h) return false;
    for (int i = 0; i < len; ++i) {
        for (int j = i + 1; j <= len; ++j) {
            for (int k = j + 1; k <= len; ++k) {
                int new_nums[len];
                memcpy(new_nums, nums, sizeof(int) * len);
                memcpy(new_nums + i, nums + j, sizeof(int) * (k - j));
                memcpy(new_nums + (i + k - j), nums + i, sizeof(int) * (j - i));
                if (cut(new_nums, d - 1)) return true;
            }
        }
    }
    return false;
}


int solve(const int *nums) {
    int ans = 0;

    while (ans <= len) {
        if (cut(nums, ans)) return ans;
        ++ans;
    }
    return ans;
}


int main() {
#ifdef AZUKI_LOCAL
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int kase = 0;
    while (cin >> len) {
        if (!len) return 0;
        int nums[len];
        rep(i, len) cin >> nums[i];
        printf("Case %d: %d\n", ++kase, solve(nums));
    }
}

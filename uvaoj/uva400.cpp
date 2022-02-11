#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define rep(i, n) for (int i = 0; i < n; ++i)
#define repr(e, i) for (auto& e : i)
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define max(a, b) a > b ? a : b;
#define min(a, b) a < b ? a : b;

using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 33;
const long long MOD = 1000000007;
const int DIRX[] = {1, 0, -1, 0};
const int DIRY[] = {0, 1, 0, -1};
typedef long long ll;

int main() {
#ifdef AZUKI_LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int count;
    string blank = "                                                            ";  // space * 60;
    while (cin >> count) {
        cout << "------------------------------------------------------------" << endl;
        vector<string> names(count);
        int length = 0;
        rep(i, count) {
            cin >> names[i];
            length = max(length, names[i].size());
        }
        sort(all(names));
        length += 2;
        int width = 62 / length;
        int height = count / width;
        if (count % width) ++height;
        vector<vector<string>> ans(height);
        int idx = 0;
        for (int j = 0; j < width; ++j) {
            for (int i = 0; i < height; ++i) {
                if (idx >= count) break;
                string output;
                if (idx + height >= count) {
                    output = names[idx] + blank.substr(0, length - names[idx].size() - 2);
                } else {
                    output = names[idx] + blank.substr(0, length - names[idx].size());
                }
                ans[i].push_back(output);
                ++idx;
            }
        }
        repr(e1, ans) {
            repr(e2, e1) {
                cout << e2;
            }
            cout << endl;
        }
    }
    return 0;
}

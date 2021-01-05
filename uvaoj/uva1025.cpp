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
#include <unordered_set>
#include <unordered_map>


#define rep(i, n) for (int i = 0; i < n; ++i)
#define repr(e, i) for (auto e: i)
#define all(x) x.begin(), x.end()
#define pii pair<int, int>


using namespace std;
const int maxn = 14;
const int inf = 0x3f3f3f3f;
typedef long long ll;

int main() {
#ifdef AZUKI_LOCAL
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int stations_count, t, m1, m2, kase = 1;
    while (scanf("%d", &stations_count) && stations_count) {
        // init
        vector<int> stations(stations_count);
        vector<int> left_accumulation(stations_count);
        stations[0] = 0;
        left_accumulation[0] = 0;

        scanf("%d", &t);
        for (int i = 1; i < stations_count; ++i) {
            scanf("%d", &stations[i]);
            left_accumulation[i] = stations[i] + left_accumulation[i - 1];
        }


        scanf("%d", &m1);
        vector<set<int> > m1_schedule(stations_count, set<int>());
        int m1_start;
        rep(i, m1) {
            scanf("%d", &m1_start);
            rep(j, stations_count) {
                m1_schedule[j].insert(m1_start + left_accumulation[j]);
            }
        }
        scanf("%d", &m2);
        int m2_start;
        vector<set<int> > m2_schedule(stations_count, set<int>());
        rep(i, m2) {
            scanf("%d", &m2_start);
            rep(j, stations_count) {
                m2_schedule[j].insert(
                        m2_start + left_accumulation[stations_count - 1] - left_accumulation[j]);
            }
        }


        // solve
        printf("Case Number %d: ", kase++);
        int dp[t + 5][stations_count];
        memset(dp, 0x3f, sizeof(dp));
        dp[0][0] = 0;
        for (int i = 1; i <= t; ++i) {
            for (int j = 0; j < stations_count; ++j) {
                dp[i][j] = dp[i - 1][j] + 1;
                if (j > 0 && m1_schedule[j].find(i) != m1_schedule[j].end()) {
                    dp[i][j] = min(dp[i][j], dp[i - stations[j]][j - 1]);
                }
                if (j < stations_count - 1 && m2_schedule[j].find(i) != m2_schedule[j].end()) {
                    dp[i][j] = min(dp[i][j], dp[i - stations[j + 1]][j + 1]);
                }
            }
        }
        if (dp[t][stations_count - 1] >= 0x3f3f3f3f) {
            cout << "impossible" << endl;
        } else {
            cout << dp[t][stations_count - 1] << endl;
        }
    }

    return 0;
}

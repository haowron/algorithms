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
    int kase;
    scanf("%d", &kase);
    rep(idx, kase) {
        int song_count, minutes;
        scanf("%d%d", &song_count, &minutes);
        vector<int> songs(song_count);
        rep(i, song_count) scanf("%d", &songs[i]);
        int dp[minutes], song_counts[minutes];
        rep(s, song_count) {
            for (int i = minutes - 1; i >= 0; --i) {
                if (!s) {
                    dp[i] = i < songs[0] ? 0 : songs[0];
                    song_counts[i] = i >= songs[0];
                } else if (i >= songs[s] && song_counts[i - songs[s]] + 1 > song_counts[i]) {
                    dp[i] = dp[i - songs[s]] + songs[s];
                    song_counts[i] = song_counts[i - songs[s]] + 1;
                } else if (i >= songs[s] && song_counts[i - songs[s]] + 1 == song_counts[i] && dp[i - songs[s]] + songs[s] >= dp[i]) {
                    dp[i] = dp[i - songs[s]] + songs[s];
                }
            }
        }
        printf("Case %d: %d %d\n", idx + 1, song_counts[minutes - 1] + 1, dp[minutes - 1] + 678);
    }
    return 0;
}
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
const int INF = 0x3f3f3f3f;
typedef long long ll;


int main() {
#ifdef AZUKI_LOCAL
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int kase;
    cin >> kase;
    int sequence_length;
    while (kase--) {
        set<vector<int> > dict;
        cin >> sequence_length;
        vector<int> sequence(sequence_length);
        vector<int> all_zero(sequence_length);
        rep(i, sequence_length) {
            cin >> sequence[i];
            all_zero[i] = 0;
        }
        dict.insert(all_zero);
        while (!dict.count(sequence)) {
            dict.insert(sequence);
            int t = sequence[0];
            rep(i, sequence_length - 1) {
                sequence[i] = abs(sequence[i + 1] - sequence[i]);
            }
            sequence[sequence_length - 1] = abs(sequence[sequence_length - 1] - t);
        }
        bool z = true;
        repr(e, sequence) {
            if (e) {
                z = false;
                break;
            }
        }
        cout << (z ? "ZERO" : "LOOP") << endl;
    }
    return 0;
}

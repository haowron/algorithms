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

using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 33;
const long long MOD = 1000000007;
const int DIRX[] = {1, 0, -1, 0};
const int DIRY[] = {0, 1, 0, -1};
typedef long long ll;

int main() {
#ifdef AZUKI_LOCAL
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif
    priority_queue<ll, vector<ll>, greater<ll> > pq;
    pq.push(1);
    unordered_set<ll> G;
    G.insert(1);
    for (int i = 1; i < 1500; ++i) {
        ll u = pq.top();
        pq.pop();
        if (G.find(u * 2) == G.end()) {
            pq.push(u * 2);
            G.insert(u * 2);
        }
        if (G.find(u * 3) == G.end()) {
            pq.push(u * 3);
            G.insert(u * 3);
        }
        if (G.find(u * 5) == G.end()) {
            pq.push(u * 5);
            G.insert(u * 5);
        }
    }
    cout << pq.top() << endl;
    return 0;
}
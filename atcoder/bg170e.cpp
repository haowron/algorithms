#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <vector>
#include <set>
#include <stack>
#include <queue>


using namespace std;
const int MAXN = 200005;
const int INF = 0x7f7f7f7f;
typedef long long ll;

int n, q;
int c, d;
int b[MAXN];
ll a[MAXN];
multiset<ll> kindergartens[MAXN];
multiset<ll> rankings;

void init_rankings() {
    for (auto & kindergarten : kindergartens) {
        if (!kindergarten.empty()) {
            rankings.insert(*kindergarten.rbegin());
        }
    }
}

int main() {
    //freopen("../input.txt", "r", stdin);
    //freopen("../output.txt", "w", stdout);
    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
        kindergartens[b[i]].insert(a[i]);
    }
    init_rankings();
    for (int i = 0; i < q; ++i) {
        cin >> c >> d;
        // make sure only one value is deleted with "find".
        rankings.erase(rankings.find(*kindergartens[b[c - 1]].rbegin()));
        if (!kindergartens[d].empty()) rankings.erase(rankings.find(*kindergartens[d].rbegin()));

        kindergartens[b[c - 1]].erase(a[c - 1]);
        kindergartens[d].insert(a[c - 1]);

        if (!kindergartens[b[c - 1]].empty()) rankings.insert(*kindergartens[b[c - 1]].rbegin());
        rankings.insert(*kindergartens[d].rbegin());

        b[c - 1] = d;
        cout << *rankings.begin() << endl;
    }
    return 0;
}

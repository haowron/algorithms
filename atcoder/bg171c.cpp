#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <vector>
#include <set>
#include <stack>
#include <queue>

#define rep(i, n) for (int i = 0; i < n; ++i)
#define all(x) x.begin(), x.end()


using namespace std;
const int MAXN = 1000005;
const int INF = 0x7f7f7f7f;
typedef long long ll;


int main() {
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    //freopen("../output.txt", "w", stdout);
#endif
    ll n;
    cin >> n;
    vector<char> v;
    while (n) {
        string al = "zabcdefghijklmnopqrstuvwxy";
        v.push_back(al[n % 26]);
        if (!(n % 26)) --n;
        n = n / 26;
    }
    for (int i = v.size(); i > 0; --i) {
        cout << v[i - 1];
    }
    cout << endl;

    return 0;
}

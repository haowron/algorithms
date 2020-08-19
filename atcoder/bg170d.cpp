#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>


using namespace std;

int n;

int a_cnt[1000000 + 5];
int ft[1000000 + 5];
int t;

int main() {
    cin >> n;
    vector<int> a;
    memset(a_cnt, 0, sizeof(a_cnt));
    memset(ft, 0, sizeof(ft));
    for (int i = 0; i < n; ++i) {
        cin >> t;
        a.push_back(t);
        ++a_cnt[t];
    }
    sort(a.begin(), a.end());
    int maxnum = a[n - 1];
    for (int i = 0; i < n; ++i) {
        t = a[i];
        if (ft[t]) continue;
        for (int j = t * 2; j <= maxnum; j=j+t) {
            ft[j] = 1;
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        t = a[i];
        if (a_cnt[t] > 1) continue;
        if (ft[t]) continue;
        ++ans;
    }
    cout << ans << endl;
}

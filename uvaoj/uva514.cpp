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
const int MAXN = 10e4;
const int INF = 0x3f3f3f3f;
typedef long long ll;


int train_count;
vector<int> train_permutation;

void solve() {
    stack<int> stk;
    queue<int> q;
    int idx = 0;
    rep(i, train_count) {
        q.push(i + 1);
    }
    int cur_train_idx;
    while (!q.empty()) {
        if (!stk.empty() && stk.top() == train_permutation[idx]) {
            ++idx;
            stk.pop();
        } else {
            cur_train_idx = q.front();
            q.pop();
            stk.push(cur_train_idx);
        }
    }
    while (!stk.empty()) {
        if (stk.top() != train_permutation[idx]) {
            cout << "No" << endl;
            return;
        }
        stk.pop();
        ++idx;
    }
    cout << "Yes" << endl;
}

int main() {
#ifdef AZUKI_LOCAL
    freopen("../input.txt", "r", stdin);
    //freopen("../output.txt", "w", stdout);
#endif
    int t;

    string input_str;
    while (getline(cin, input_str)) {
        stringstream ss(input_str);
        ss >> train_count;
        if (!train_count) break;

        while (getline(cin, input_str)) {
            ss.clear();
            ss.str(input_str);
            train_permutation.clear();
            while (ss >> t) {
                if (!t) break;
                train_permutation.push_back(t);
            }
            if (!t) break;
            solve();
        }
        cout << endl;
    }
    return 0;
}

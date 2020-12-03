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
const int maxn = 100000 + 5;
const int inf = 0x3f3f3f3f;
typedef long long ll;


void solve(const string &s) {
    stack<char> stk;
    repr(e, s) {
        if (e == ')') {
            if (!stk.empty() && stk.top() == '(') {
                stk.pop();
            } else {
                cout << "No" << endl;
                return;
            }
        } else if (!stk.empty() && e == ']') {
            if (stk.top() == '[') {
                stk.pop();
            } else {
                cout << "No" << endl;
                return;
            }
        } else {
            stk.push(e);
        }
    }
    if (stk.empty()) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}

int main() {
#ifdef AZUKI_LOCAL
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int kase;
    cin >> kase;
    string s;
    getline(cin ,s);
    while (kase--) {
        getline(cin ,s);
        solve(s);
    }
    return 0;
}

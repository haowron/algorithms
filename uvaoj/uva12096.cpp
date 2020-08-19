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
const int INF = 0x7f7f7f7f;
typedef long long ll;

// set的key是不是int并不重要
typedef set<int> Set ;
// Set 和 int 双向查找
vector<Set> v;
map<Set, int> m;


int get_id(const Set& s){
    if(m.count(s)) return m[s];
    v.push_back(s);
    return m[s] = v.size()-1;
}


int main() {
#ifndef ONLINE_JUDGE
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);
#endif
    int ca, n;
    string ins;
    cin >> ca;
    while (ca--) {
        cin >> n;
        v.clear();
        m.clear();
        stack<int> stk;
        rep(i, n) {
            cin >> ins;
            if (ins[0] == 'P') {
                stk.push(get_id(Set()));
            } else if (ins[0] == 'D') {
                stk.push(stk.top());
            } else if (ins[0] == 'U') {
                Set s1 = v[stk.top()];
                stk.pop();
                Set s2 = v[stk.top()];
                stk.pop();
                Set s3;
                set_union(all(s1), all(s2), inserter(s3,s3.begin()));
                stk.push(get_id(s3));
            } else if (ins[0] == 'I') {
                Set s1 = v[stk.top()];
                stk.pop();
                Set s2 = v[stk.top()];
                stk.pop();
                Set s3;
                set_intersection(all(s1), all(s2), inserter(s3,s3.begin()));
                stk.push(get_id(s3));
            } else if (ins[0] == 'A') {
                Set s1 = v[stk.top()];
                stk.pop();
                Set s2 = v[stk.top()];
                stk.pop();
                Set s3;
                s3 = s2;
                s3.insert(get_id(s1));
                stk.push(get_id(s3));
            }
            cout << v[stk.top()].size() << endl;
        }
        cout << "***" << endl;
    }
    return 0;
}

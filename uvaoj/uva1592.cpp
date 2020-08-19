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
#include <unordered_map>

#define rep(i, n) for (int i = 0; i < n; ++i)
#define repr(e, i) for (auto e: i)
#define all(x) x.begin(), x.end()


using namespace std;
const int MAXN = 10e5 + 5;
const int INF = 0x7f7f7f7f;
typedef long long ll;

vector<string> records;
unordered_map<string, int> dic;

int columns, rows;
int c1, c2, r1, r2;

int get_id(const string &s) {
    if (dic.count(s)) return dic[s];
    records.push_back(s);
    return dic[s] = records.size() - 1;
}

bool solve() {
    records.clear();
    dic.clear();
    vector<string> vs(rows);
    int d[rows][columns];

    rep(i, rows) {
        string t;
        getline(cin, t);
        vs[i] = t;
    }
    rep(i, rows) {
        string row = vs[i];
        int last_position = 0;
        rep(j, columns) {
            int position = row.find(',', last_position);
            if (position == string::npos) position = row.size();
            d[i][j] = get_id(row.substr(last_position, position - last_position));
            last_position = position + 1;
        }
    }
    for (c2 = 1; c2 < columns; ++c2) {
        for (c1 = 0; c1 < c2; ++c1) {
            map<pair<int, int>, int> m;
            rep(i, rows) {
                if (m.count({d[i][c1], d[i][c2]})) {
                    r1 = m[{d[i][c1], d[i][c2]}];
                    r2 = i;
                    return true;
                } else {
                    m[{d[i][c1], d[i][c2]}] = i;
                }
            }
        }
    }
    return false;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    //freopen("../output.txt", "w", stdout);
#endif
    string s;
    while (getline(cin, s)) {
        stringstream ss(s);
        ss >> rows >> columns;
        if (solve()) {
            cout << "NO" << endl << r1 + 1 << " " << r2 + 1 << endl << c1 + 1 << " " << c2 + 1 << endl;
        } else {
            cout << "YES" << endl;
        }
    }
    return 0;
}

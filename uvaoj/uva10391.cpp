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

int get_size(const string &s) {
    return s.size() > 1000 ? 1000 : s.size();
}

int main() {
#ifdef AZUKI_LOCAL
    freopen("../input.txt", "r", stdin);
    //freopen("../output.txt", "w", stdout);
#endif
    string s;
    // segregated list
    vector<set<string> > container(1005);
    vector<string> all_strings;
    int s_size;
    while (cin >> s) {
        s_size = get_size(s);
        container[s_size].insert(s);
        all_strings.push_back(s);
    }
    repr(k, all_strings) {
        for (int i = 1; i < k.size(); ++i) {
            string fst = k.substr(0, i);
            string snd = k.substr(i, k.size() - 1);
            if (container[get_size(fst)].count(fst) && container[get_size(snd)].count(snd)) {
                cout << k << endl;
                break;
            }
        }
    }
    return 0;
}

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

#define rep(i, n) for (int i = 0; i < n; ++i)
#define repr(e, i) for (auto e: i)
#define all(x) x.begin(), x.end()


using namespace std;
const int MAXN = 10e5 + 5;
const int INF = 0x3f3f3f3f;
typedef long long ll;


int main() {
#ifndef ONLINE_JUDGE
    //freopen("../input.txt", "r", stdin);
    //freopen("../output.txt", "w", stdout);
#endif
    string s;
    char str;
    bool is_first= true;
    int i=0;
    while (true){
        str = getchar();
        if(str=='\0' || str == -1) break;
        else if(str == '"'){
            if(is_first){
                cout << "``";
                is_first = false;
            } else {
                cout << "''";
                is_first = true;
            }

        } else {
            cout << str;
        }
    }
    return 0;
}

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
const int MAXN = 10e4;
const int INF = 0x3f3f3f3f;
typedef long long ll;


int main() {
#ifdef AZUKI_LOCAL
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int cards_count;
    while (cin >> cards_count){
        if(!cards_count) break;
        vector<int> cards(MAXN);
        rep(i, cards_count) cards[i]=i+1;
        int begin = 0, end = cards_count;
        cout << "Discarded cards:";
        while (begin != end-1){
            if(begin) cout << ", "<< cards[begin];
            else cout << " "<< cards[begin];
            cards[end] = cards[begin+1];
            begin+=2;
            ++end;
        }
        cout << endl << "Remaining card: " << cards[begin] << endl;
    }


    return 0;
}

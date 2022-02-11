#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define rep(i, n) for (int i = 0; i < n; ++i)
#define repr(e, i) for (auto& e : i)
#define all(x) x.begin(), x.end()
#define pii pair<int, int>

using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 33;
const long long MOD = 1000000007;
const int DIRX[] = {1, 0, -1, 0};
const int DIRY[] = {0, 1, 0, -1};
typedef long long ll;

int main() {
#ifdef AZUKI_LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int queue_count;
    int member_count;
    int member;
    string command;
    int kase = 1;
    while (cin >> queue_count) {
        if (!queue_count) return 0;
        printf("Scenario #%d\n", kase);
        ++kase;
        unordered_map<int, int> G;
        queue<int> q, q2[queue_count];
        rep(i, queue_count) {
            cin >> member_count;
            rep(j, member_count) {
                cin >> member;
                G[member] = i;
            }
        }

        while (cin >> command) {
            if (command == "STOP")
                break;
            else if (command == "DEQUEUE") {
                int idx = q.front();
                printf("%d\n", q2[idx].front());
                q2[idx].pop();
                if (q2[idx].empty()) q.pop();
            } else {
                cin >> member;
                if(q2[G[member]].empty()) q.push(G[member]);
                q2[G[member]].push(member);
            }
        }
        printf("\n");
    }

    return 0;
}
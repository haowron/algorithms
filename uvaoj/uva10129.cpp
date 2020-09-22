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
const int maxn = 105;
const int inf = 0x3f3f3f3f;
typedef long long ll;

int words[30][30];
int has_words[30];

bool check_circuit() {
    int c = 0;
    int visited[30];
    memset(visited, 0, sizeof(visited));
    rep(i, 30) {
        if (c > 1) return false;
        queue<int> q;
        if (!visited[i] && has_words[i]) {
            q.push(i);
            visited[i] = 1;
            ++c;
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                rep(v, 30) {
                    //cout << (char) ('a' + v) << endl;
                    if (!visited[v] && (words[u][v] || words[v][u])) {
                        visited[v] = 1;
                        q.push(v);
                    }
                }
            }
        }
    }
    return true;
}

bool check_euler() {
    int p = 0;
    rep(i, 30) {
        int entrance=0, exit=0;
        rep(j, 30) {
            entrance += words[i][j];
            exit += words[j][i];
        }
        int d = abs(entrance - exit);
        if (d > 1) return false;
        else if (d) {
            ++p;
        }
    }
    return p < 3;
}

int main() {
#ifdef AZUKI_LOCAL
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int kase, words_num;
    string word;
    cin >> kase;
    while (kase--) {
        cin >> words_num;
        memset(words, 0, sizeof(words));
        memset(has_words, 0, sizeof(has_words));
        for (int i = 0; i < words_num; ++i) {
            cin >> word;
            ++words[word[0] - 'a'][word[word.size() - 1] - 'a'];
            has_words[word[0] - 'a'] = 1;
            has_words[word[word.size() - 1] - 'a'] = 1;
        }
        if (check_circuit() && check_euler()) {
            cout << "Ordering is possible." << endl;
        } else {
            cout << "The door cannot be opened." << endl;
        }
    }
    return 0;
}

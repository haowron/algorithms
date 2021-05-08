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
#include <unordered_set>
#include <unordered_map>


#define rep(i, n) for (int i = 0; i < n; ++i)
#define repr(e, i) for (auto e: i)
#define all(x) x.begin(), x.end()
#define pii pair<int, int>


using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 33;
typedef long long ll;
const long long mod = 1000000007;

// https://atcoder.jp/contests/typical90/tasks/typical90_e
// https://github.com/E869120/kyopro_educational_90/blob/main/editorial/005-03.jpg
// 这题没看懂，贴一个官方解（其实看懂了，但我写不出来


long long modpow(long long a, long long b, long long m) {
    long long p = 1, q = a;
    for (int i = 0; i < 63; i++) {
        if ((b & (1LL << i)) != 0) {
            p *= q;
            p %= m;
        }
        q *= q;
        q %= m;
    }
    return p;
}

const long long mod = 1000000007;

// 入力
long long N, B, K;
long long C[11];

// その他の変数
long long power10[64];
long long DP[64][1009];
long long Answer[64][1009];

int main() {
    // Step #1. 入力
    cin >> N >> B >> K;
    for (int i = 1; i <= K; i++) cin >> C[i];

    // Step #2. 前計算
    for (int i = 0; i <= 62; i++) {
        power10[i] = modpow(10LL, (1LL << i), B);
    }

    // Step #3. dp[1][i] を求める
    for (int i = 1; i <= K; i++) {
        DP[0][C[i] % B] += 1;
    }

    // Step #4. dp[1][i], dp[2][i], ..., dp[2^n][i] を求める
    for (int i = 0; i < 62; i++) {
        for (int j = 0; j < B; j++) {
            for (int k = 0; k < B; k++) {
                int nex = (j * power10[i] + k) % B;
                DP[i + 1][nex] += DP[i][j] * DP[i][k];
                DP[i + 1][nex] %= mod;
            }
        }
    }

    // Step #5. 繰り返し二乗法により dp[N][i] を求める
    Answer[0][0] = 1;
    for (int i = 0; i < 62; i++) {
        if ((N & (1LL << i)) != 0LL) {
            for (int j = 0; j < B; j++) {
                for (int k = 0; k < B; k++) {
                    int nex = (j * power10[i] + k) % B;
                    Answer[i + 1][nex] += Answer[i][j] * DP[i][k];
                    Answer[i + 1][nex] %= mod;
                }
            }
        }
        else {
            for (int j = 0; j < B; j++) Answer[i + 1][j] = Answer[i][j];
        }
    }

    // Step #6. 出力
    cout << Answer[62][0] << endl;
    return 0;
}
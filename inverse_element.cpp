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
const long long mod = 1000000007;
const int dirx[] = {1, 0, -1, 0};
const int diry[] = {0, 1, 0, -1};
typedef long long ll;


/*
 * 乘法逆元 inverse element
 * 定义 若在mod p的意义下，对于一个整数 a， 有(a*x)%p = 1，那么这个整数x即为a的乘法逆元，
 * 同时a也为x的乘法逆元
 *
 * 应用 求取(a/b)%p 可以转换为 a*(b的逆元)%p
 *
 * 求b的逆元可以通过费马小定理求
 *
 * 费马小定理，如果a是p的倍数
 * 则：(a^p)%p = a
 * 如果a不是p的倍数（实际情况下通常p是质数）
 * 如果a不是p的倍数，(a^(p-1))%p = 1
 *
 * 根据费马小定理有 (a*a^(p-2))%p = 1
 * 则 a^(p-2)则为a的逆元（使用 a^(p-2)%p）
 * 这里可以使用快速幂进行计算逆元
 */

ll get_mod_inverse(ll a, ll p) {
    //这里假定p是质数
    ll ans = 1;
    a %= p;
    ll b = p - 2;
    while (b > 0) {
        if (b & 1) ans = ans * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return ans;
}


int main() {
#ifdef AZUKI_LOCAL
    freopen("../input.txt", "r", stdin);
    //freopen("../output.txt", "w", stdout);
#endif
    int n;
    cout << get_mod_inverse(5, 3) << endl;
    return 0;
}

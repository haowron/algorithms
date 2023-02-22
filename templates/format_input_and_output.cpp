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


// 格式化输入与输出
int main() {
#ifndef ONLINE_JUDGE
    // 3 4 5.5
    // 2 4test 4.5
    // a
    // s3 test space test
    //freopen("../input.txt", "r", stdin);
    //freopen("../output.txt", "w", stdout);
#endif
    // 格式化输入
    // cin 输入
    int a;
    cin >> a;
    string s;
    cin >> s;
    float f;
    cin >> f;
    cout << a << " " << s << " " << f << endl;
    // scanf 输入
    int a2;
    char s2[100];
    float f2;
    scanf("%d%s%f", &a2, &s2, &f2);
    cout << a2 << " " << s2 << " " << f2 << endl;
    //getchar 输入
    //getchar 会从4.5之后开始读取，所以输出结果是 【回车】【a】【回车】
    char c;
    rep(i, 3) {
        c = getchar();
        cout << c;
    }
    cout << endl;
    // gets 输入
    char s3[100];
    gets(s3);
    cout << s3 << endl;
    // getline输入，一次输入一整行，和其他输入不共享fd指针（也就是说这玩意不能和其他的混用）
    getline(cin ,s);


    // 格式化输出
    // cout
    int x = 11;
    cout << x << endl;
    // printf -| 作为结尾标记
    // 正常输出
    printf("%d-|\n", x);
    // 左边空格补位（默认）
    printf("%4d-|\n", x);
    // 减号右边空格补位
    printf("%-4d-|\n", x);
    // 使用0补位
    printf("%04d-|\n", x);
    // 小数的输出
    float pi = 3.14159265;
    // 通常输出
    printf("%f\n", pi);
    // 保留2位
    printf("%.2f\n", pi);
    // 一共8位（包括小数点，小数部分保留3位，不足空格补齐
    printf("%8.3f\n", pi);
    return 0;
}

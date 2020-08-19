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
const int INF = 0x3f3f3f3f;
typedef long long ll;


struct building {
    double left;
    double y;
    double right;
    double height;
    int idx;
};

bool compare(building a, building b) {
    return a.left < b.left || a.left == b.left && a.y < b.y;
}

int main() {
#ifndef ONLINE_JUDGE
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);
#endif
    int building_count, depth;
    int kase = 0;
    while (cin >> building_count) {
        set<int> x_set;
        int building_ids[building_count + 5];
        memset(building_ids, 0, sizeof(building_ids));
        vector<building> ans;
        if (!building_count) break;
        vector<building> buildings(building_count);
        rep(i, building_count) {
            building b{};
            cin >> b.left >> b.y >> b.right >> depth >> b.height;
            b.right = b.right + b.left;
            b.idx = i + 1;
            x_set.insert(b.left);
            x_set.insert(b.right);
            buildings[i] = b;
        }
        sort(buildings.begin(), buildings.end(), compare);
        sort(all(buildings), compare);
        int start_x = -1;
        repr(left_x, x_set) {
            if (start_x == -1) {
                start_x = left_x;
                continue;
            }
            double middle_x = (start_x + left_x) / 2.0;
            start_x = left_x;

            repr(b, buildings) {
                if (b.left > middle_x || b.right < middle_x) continue;
                bool visible = true;
                repr(front_b, buildings) {
                    if (front_b.left > middle_x || front_b.right < middle_x) continue;
                    if (front_b.y < b.y && front_b.height >= b.height) {
                        visible = false;
                        break;
                    }
                }

                if (visible && !building_ids[b.idx]) {
                    ans.push_back(b);
                    building_ids[b.idx] = 1;
                }
            }

        }
        if (kase) printf("\n");
        printf("For map #%d, the visible buildings are numbered as follows:\n", ++kase);
        // 题目要求是按照建筑物左下角坐标排序输出，而不是按照出现顺序排序输出
        sort(all(ans), compare);
        rep(a, ans.size() - 1) {
            cout << ans[a].idx << " ";
        }
        cout << ans[ans.size() - 1].idx << endl;
    }
    return 0;
}

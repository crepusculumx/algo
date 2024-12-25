#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    int minimumCost(int m, int n, vector<int> &horizontalCut, vector<int> &verticalCut) {
        priority_queue<pair<int, int> > q;
        for (int horizontal_cut: horizontalCut) {
            q.emplace(horizontal_cut, 1);
        }
        for (int vertical_cut: verticalCut) {
            q.emplace(vertical_cut, 0);
        }
        int h = 1, v = 1;
        int ans = 0;
        while (!q.empty()) {
            auto [cost, ish] = q.top();
            q.pop();
            if (ish == 1) {
                ans += cost * v;
                h++;
            }else {
                ans += cost * h;
                v++;
            }
        }
        return ans;
    }
};

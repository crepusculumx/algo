#include <numeric>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    int eatenApples(vector<int> &apples, vector<int> &days) {
        int n = apples.size();
        int m = 0;
        auto q = priority_queue<pair<int, int>, deque<pair<int, int> >, greater<> >();
        for (int i = 0; i < n; ++i) {
            q.emplace(i + days[i], apples[i]);
            m = max(m, i + days[i]);
        }

        int ans = 0;
        for (int i = 0; i < 4 * 1e4 + 7; i++) {
            while (!q.empty() && q.top().first < i) {
                q.pop();
            }
            if (q.empty()) { break; }
            auto t = q.top();
            q.pop();
            ans++;
            t.second--;
            if (t.second) {
                q.push(t);
            }
        }
        return ans;
    }
};

#include <vector>

using namespace std;

class Solution {
 public:
  int maxProfit(vector<int> &prices) {
    int n = prices.size();
    auto pre = vector<int>(n);

    pre[0] = prices[0];
    for (int i = 1; i < n; ++i) {
      pre[i] = min(prices[i], pre[i - 1]);
    }

    int ans = 0;

    for (int i = 0; i < n; ++i) {
      ans = max(ans, prices[i] - pre[i]);
    }
    return ans;
  }
};
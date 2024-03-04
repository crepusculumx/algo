#include <vector>

using namespace std;

class Solution {
 public:
  int maxProfit(vector<int> &prices) {
    int ans = 0;
    int cur = prices[0];

    for (const auto &price : prices) {
      if (price > cur) {
        ans += price - cur;
        cur = price;
      } else if (price == cur) {
        continue;
      } else {
        cur = price;
      }
    }

    return ans;
  }
};
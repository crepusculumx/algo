#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int countWays(vector<vector<int>> &ranges) {
    constexpr int mod = 1e9 + 7;
    long long cnt = 1;
    int r = -1;

    std::sort(ranges.begin(), ranges.end());

    for (const auto &range : ranges) {
      int cur_l = range[0];
      int cur_r = range[1];

      if (cur_l <= r) {
        r = max(r, cur_r);
      } else {
        r = cur_r;
        cnt = cnt * 2 % mod;
      }
    }
    return (int) cnt;
  }
};
int main() {
  std::cout << "Hello, World!" << std::endl;
  return 0;
}

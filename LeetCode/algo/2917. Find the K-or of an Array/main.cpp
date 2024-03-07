#include <vector>

using namespace std;

class Solution {
 public:
  int findKOr(vector<int> &nums, int k) {
    auto cnt = vector<int>(32, 0);
    for (unsigned int num : nums) {
      for (int i = 0; i < 32; ++i) {
        cnt[i] += (((1 << i) & num) == (1 << i));
      }
    }
    int res = 0;
    for (int i = 0; i < 32; ++i) {
      if (cnt[i] >= k) {
        res += 1 << i;
      }
    }
    return res;
  }
};
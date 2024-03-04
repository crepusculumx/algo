#include <vector>

using namespace std;

class Solution {
 public:
  int majorityElement(vector<int> &nums) {
    int sum = 0;
    int res = nums[0];

    for (const auto &item : nums) {
      if (sum == 0) { res = item; }

      if (item == res) { ++sum; }
      else { --sum; }
    }

    return res;
  }
};
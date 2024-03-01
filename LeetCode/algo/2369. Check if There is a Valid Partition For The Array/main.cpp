#include <vector>
#include <functional>

using namespace std;

class Solution {
 public:
  bool validPartition(vector<int> &nums) {
    auto isOk1 = [&nums](int p) {
      if (p + 1 >= nums.size()) { return false; }
      return nums[p] == nums[p + 1];
    };

    auto isOk2 = [&nums](int p) {
      if (p + 2 >= nums.size()) { return false; }
      return nums[p] == nums[p + 1] && nums[p + 1] == nums[p + 2];
    };

    auto isOk3 = [&nums](int p) {
      if (p + 2 >= nums.size()) { return false; }
      return nums[p] == nums[p + 1] - 1 && nums[p + 1] == nums[p + 2] - 1;
    };

    auto memo = vector<int>(nums.size(), -1);
    function<bool(int)> dfs = [&](int cur) {
      if (cur == nums.size()) { return true; }

      if (memo[cur] != -1) { return (bool) memo[cur]; }

      if (isOk1(cur)) {
        if (dfs(cur + 2)) { return (bool) (memo[cur] = true); }
      }
      if (isOk2(cur)) {
        if (dfs(cur + 3)) { return (bool) (memo[cur] = true); }
      }
      if (isOk3(cur)) {
        if (dfs(cur + 3)) { return (bool) (memo[cur] = true); }
      }
      return (bool) (memo[cur] = false);
    };

    return dfs(0);
  }
};
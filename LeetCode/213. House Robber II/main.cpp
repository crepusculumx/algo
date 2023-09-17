#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

class Solution {
 private:
  int memo[100 + 7][2][2];

  int dfs(vector<int> &nums, int pos, bool can_rob, bool first_rob) {
    if (pos == nums.size()) { return 0; }

    int &cur_memo = memo[pos][can_rob][first_rob];
    if (cur_memo != -1) { return cur_memo; }

    int res = 0;

    if (can_rob && !(pos == nums.size() - 1 && first_rob)) {
      pos == 0 ?
          res = max(res, nums[pos] + dfs(nums, pos + 1, false, true)) :
          res = max(res, nums[pos] + dfs(nums, pos + 1, false, first_rob));
    }
    res = max(res, dfs(nums, pos + 1, true, first_rob));

    cur_memo = res;
    return res;
  }
 public:
  int rob(vector<int> &nums) {
    memset(memo, -1, sizeof(memo));
    if (nums.size() == 1) { return nums[0]; }
    if (nums.size() == 2) { return max(nums[0], nums[1]); }

    return dfs(nums, 0, true, false);
  }
};

int main() {
  Solution solution{};
  auto v = vector<int>{200, 3, 140, 20, 10};
  cout << solution.rob(v);
  return 0;
}

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 private:
  static constexpr int INF = 1e9 + 7;

  bool check(const vector<int> &nums, int cap, int k) {
    int cnt = 0;
    bool can_rob = true;
    for (const auto &item : nums) {
      if (!can_rob) {
        can_rob = true;
        continue;
      }
      if (item <= cap) {
        can_rob = false;
        cnt++;
      }
      if (cnt >= k) return true;
    }
    return false;
  }

  int two(int l, int r, const vector<int> &nums, int k) {
    if (r - l < 7) {
      for (int i = l; i <= r; i++) {
        if (check(nums, i, k)) {
          return i;
        }
      }
      return INF;
    }
    int mid = (l + r) / 2;
    if (check(nums, mid, k)) {
      return two(l, mid, nums, k);
    } else {
      return two(mid, r, nums, k);
    }
  }
 public:
  int minCapability(vector<int> &nums, int k) {
    return two(0, INF, nums, k);
  }
};

int main() {
  std::cout << "Hello, World!" << std::endl;
  return 0;
}

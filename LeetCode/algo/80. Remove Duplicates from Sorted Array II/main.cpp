#include <vector>

using namespace std;

class Solution {
 public:
  int removeDuplicates(vector<int> &nums) {
    auto p1 = nums.begin();
    auto p2 = nums.begin() + 1;

    bool flag = false;
    while (p2 != nums.end()) {
      if (*p2 != *p1) {
        flag = false;
        swap(*p2, *(p1 + 1));
        ++p1;
        ++p2;
        continue;
      }

      if (*p2 == *p1 && !flag) {
        flag = true;
        swap(*p2, *(p1 + 1));
        ++p1;
        ++p2;
        continue;
      }
      ++p2;
    }
    return distance(nums.begin(), p1) + 1;
  }
};
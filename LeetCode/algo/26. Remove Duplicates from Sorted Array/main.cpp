#include <vector>

using namespace std;

class Solution {
 public:
  int removeDuplicates(vector<int> &nums) {
    auto p1 = nums.begin();
    auto p2 = nums.begin() + 1;
    while (p2 != nums.end()) {
      if (*p2 != *p1) {
        swap(*p2, *(p1 + 1));
        ++p1;
      }
      ++p2;
    }
    return distance(nums.begin(), p1) + 1;
  }
};
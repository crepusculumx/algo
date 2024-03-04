#include <vector>

using namespace std;

class Solution {
 public:
  void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
    while (nums1.size() > m) {
      nums1.pop_back();
    }

    vector<int> res;

    auto p1 = nums1.begin();
    auto p2 = nums2.begin();

    while (p1 != nums1.end() || p2 != nums2.end()) {
      if (p1 == nums1.end()) {
        res.emplace_back(*p2);
        ++p2;
      } else if (p2 == nums2.end()) {
        res.emplace_back(*p1);
        ++p1;
      } else {
        if (*p1 < *p2) {
          res.emplace_back(*p1);
          ++p1;
        } else {
          res.emplace_back(*p2);
          ++p2;
        }
      }
    }

    nums1 = res;
  }
};
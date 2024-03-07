#include <vector>
#include <string>

using namespace std;

class Solution {
 public:
  vector<int> divisibilityArray(string word, int m) {
    auto res = vector<int>();
    long long sum = 0;
    for (const auto &c : word) {
      sum *= 10;
      sum %= m;
      sum += c - '0';
      sum %= m;
      if (sum % m == 0) {
        res.emplace_back(1);
      } else {
        res.emplace_back(0);
      }
    }
    return res;
  }
};
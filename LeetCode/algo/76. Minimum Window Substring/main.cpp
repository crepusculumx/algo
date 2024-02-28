#include <string>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
 public:
  string minWindow(string s, string t) {
    auto sMap = unordered_map<char, int>();
    auto tMap = unordered_map<char, int>();

    for (const auto &c : t) {
      ++tMap[c];
    }

    auto isOk = [&sMap, &tMap]() {
      for (const auto &[tc, ts] : tMap) {
        if (!sMap.contains(tc)) { return false; }
        if (sMap[tc] < ts) { return false; }
      }
      return true;
    };

    size_t resLen = 0x7FFFFFFF;
    auto resL = s.begin();
    auto resR = s.begin();

    auto l = s.begin();
    auto r = s.begin();

    while (r != s.end()) {
      while (!isOk() && r != s.end()) {
        ++sMap[*r];
        ++r;
      }
      while (isOk() && l != s.end()) {
        if (distance(l, r) < resLen) {
          resLen = distance(l, r);
          resL = l;
          resR = r;
        }
        --sMap[*l];
        ++l;
      }
    }

    string res;

    for (auto i = resL; i < resR; ++i) {
      res += *i;
    }
    return res;
  }
};

int main() {
  Solution s;
  cout << s.minWindow("ADOBECODEBANC", "ABC");
}
#include <vector>
#include <functional>
#include <iostream>

using namespace std;

class Solution {
 public:
  int minIncrements(int n, vector<int> &cost) {
    //  [0, (n-1)]
    cost.insert(cost.begin(), 0);

    // <cost, len>
    function<std::pair<int, int>(int)> dfs = [&dfs, n, &cost](int cur) {
      if (cur > n / 2) { return make_pair(0, cost[cur]); }
      int l = cur * 2;
      int r = cur * 2 + 1;

      auto fl = dfs(l);
      auto fr = dfs(r);

      int newCost = fl.first + fr.first + abs(fl.second - fr.second);
      int newLen = max(fl.second, fr.second) + cost[cur];
      return make_pair(newCost, newLen);
    };

    return dfs(1).first;
  }
};


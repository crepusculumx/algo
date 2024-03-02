#include <vector>
#include <functional>

using namespace std;

class Solution {
 public:
  int reachableNodes(int n, vector<vector<int>> &edges, vector<int> &restricted) {
    auto adj = vector<vector<int>>(n);
    for (const auto &item : edges) {
      adj[item[0]].emplace_back(item[1]);
      adj[item[1]].emplace_back(item[0]);
    }

    auto isRestricted = vector<bool>(n, false);
    for (const auto &item : restricted) {
      isRestricted[item] = true;
    }

    function<int(int, int)> dfs = [&](int cur, int fa) {
      if (isRestricted[cur]) { return 0; }
      int res = 1;
      for (const auto &v : adj[cur]) {
        if (v == fa) { continue; }
        res += dfs(v, cur);
      }
      return res;
    };

    return dfs(0, 0);
  }
};
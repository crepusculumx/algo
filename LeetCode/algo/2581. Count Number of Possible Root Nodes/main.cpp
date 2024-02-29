#include <iostream>
#include <vector>
#include <unordered_set>
#include <functional>

using namespace std;
namespace std {
template<>
struct hash<std::pair<int, int>> {
  size_t operator()(const std::pair<int, int> &rhs) const {
    return rhs.first << 31 | rhs.second;
  }
};
}

class Solution {
 public:
  int rootCount(vector<vector<int>> &edges, vector<vector<int>> &guesses, int k) {
    int n = edges.size() + 1;
    auto adj = vector<vector<int>>(n);

    for (const auto &edge : edges) {
      adj[edge[0]].emplace_back(edge[1]);
      adj[edge[1]].emplace_back(edge[0]);
    }

    auto s = unordered_set<std::pair<int, int>>();
    for (const auto &item : guesses) {
      s.emplace(item[0], item[1]);
    }

    function<int(int, int)> dfs = [&dfs, &adj, &s](int cur, int fa) {
      int res = 0;
      for (const auto &v : adj[cur]) {
        if (v == fa) { continue; }
        if (s.contains(std::make_pair(cur, v))) { ++res; }
        res += dfs(v, cur);
      }
      return res;
    };

    int cnt = dfs(0, 0);
    int res = 0;

    function<void(int, int, int)> dfs2 = [&dfs2, &res, &adj, &s, k](int cur, int fa, int sum) {
      if (sum >= k) { ++res; }
      for (const auto &v : adj[cur]) {
        if (v == fa) { continue; }
        dfs2(v, cur, sum - s.count(make_pair(cur, v)) + s.count(make_pair(v, cur)));
      }
    };

    dfs2(0, 0, cnt);
    return res;
  }
};
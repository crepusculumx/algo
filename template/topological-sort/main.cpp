#include <iostream>
#include <vector>
#include <functional>

using namespace std;

vector<int> TopologicalSort(const vector<vector<int>> &adj) {
  auto n = adj.size();
  auto rev_adj = vector<vector<int>>(n);

  for (int u = 0; u < n; ++u) {
    for (const auto &v : adj[u]) {
      rev_adj[v].emplace_back(u);
    }
  }

  // 字典序
  for (auto &pre : rev_adj) {
    std::sort(pre.begin(), pre.end());
  }

  auto vis = vector<bool>(n, false);
  auto res = vector<int>();

  function<void(int)> dfs = [&dfs, &rev_adj, &vis, &res](int cur) {
    if (vis[cur]) { return; }
    for (const auto &pre : rev_adj[cur]) {
      dfs(pre);
    }
    res.emplace_back(cur);
    vis[cur] = true;
  };

  for (int i = 0; i < n; ++i) {
    dfs(i);
  }
  return res;
}

int main() {
  int n;
  cin >> n;
  auto adj = vector<vector<int>>(n);
  for (int i = 0; i < n; ++i) {
    while (true) {
      int t;
      cin >> t;
      if (!t) { break; }
      t--;
      adj[i].emplace_back(t);
    }
  }
  auto res = TopologicalSort(adj);
  for (const auto &item : res) {
    cout << item + 1 << " ";
  }
  return 0;
}

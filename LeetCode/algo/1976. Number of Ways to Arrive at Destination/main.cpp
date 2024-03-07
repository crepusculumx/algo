#include <vector>
#include <queue>
#include <functional>
#include <map>

using namespace std;

constexpr long long INF = 0x3f3f3f3f3f3f3f3f;
constexpr long long MOD = 1e9 + 7;

struct Edge {
  int v;
  long long w;
  Edge(int v, long long w) : v(v), w(w) {}
};

class Solution {
 public:
  int countPaths(int n, vector<vector<int>> &roads) {
    auto adj = vector<vector<Edge>>(n);
    for (const auto &item : roads) {
      adj[item[0]].emplace_back(item[1], item[2]);
      adj[item[1]].emplace_back(item[0], item[2]);
    }
    auto dis = vector<long long>(n, INF);
    dis[0] = 0;

    auto q = queue<int>();
    q.push(0);

    while (!q.empty()) {
      auto u = q.front();
      q.pop();

      for (const auto &edge : adj[u]) {
        auto v = edge.v;
        auto w = edge.w;

        if (dis[u] + w < dis[v]) {
          dis[v] = dis[u] + w;
          q.push(v);
        }
      }
    }

    auto memo = map<pair<int, long long>, long long>();

    function<int(int, long long)> dfs = [&](int u, long long d) -> long long {
      if (u == n - 1) { return 1; }

      if (memo.contains(make_pair(u, d))) {
        return memo[make_pair(u, d)];
      }
      int ans = 0;
      for (const auto &[v, w] : adj[u]) {
        if (d + w == dis[v]) {
          ans += dfs(v, d + w);
          ans %= MOD;
        }
      }
      return memo[make_pair(u, d)] = ans;
    };
    return dfs(0, 0);
  }
};
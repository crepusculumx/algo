#include <iostream>
#include <vector>

using namespace std;

using AdjMatrix = vector<vector<int>>;
constexpr int INF = 0x3f3f3f3f;

vector<vector<int>> floyd(const AdjMatrix &adj) {
  auto n = adj.size();
  auto dp1 = adj;
  auto dp2 = adj;

  for (int i = 0; i < n; ++i) {
    dp1[i][i] = 0;
  }

  for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        dp2[i][j] = min(dp1[i][j], dp1[i][k] + dp2[k][j]);
      }
    }
    dp1 = dp2;
  }
  return dp2;
}

int main() {
  int n, m;
  cin >> n >> m;
  auto adj = AdjMatrix(n, vector<int>(n, INF));
  for (int i = 0; i < m; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    u--;
    v--;
    adj[u][v] = min(adj[u][v], w); // 重边
    adj[v][u] = min(adj[v][u], w);
  }
  auto res = floyd(adj);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cout << res[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}

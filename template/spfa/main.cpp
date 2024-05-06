#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Edge {
  int v, w;
  Edge(int v1, int w1) : v(v1), w(w1) {}
};

using Adj = std::vector<std::vector<Edge>>;
constexpr int INF = 0x3f3f3f3f;

vector<int> spfa(const Adj &adj, int s) {
  auto dis = vector<int>(adj.size(), INF);
  auto inQueue = vector<bool>(adj.size(), false);
  auto q = queue<int>();

  q.push(s);
  dis[s] = 0;
  inQueue[s] = true;

  while (!q.empty()) {
    auto u = q.front();
    q.pop();
    inQueue[u] = false;

    for (const auto &[v, w] : adj[u]) {
      if (dis[u] + w < dis[v]) {
        dis[v] = dis[u] + w;
        if (!inQueue[v]) {
          q.push(v);
          inQueue[v] = true;
        }

      }
    }
  }
  return dis;
}

int main() {
  int n, m, s;
  cin >> n >> m >> s;
  s--;

  auto adj = Adj(n);
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    u--;
    v--;
    adj[u].emplace_back(v, w);
  }
  auto dis = spfa(adj, s);
  for (auto &d : dis) {
    printf("%d ", d == INF ? 0x7fffffff : d);
  }
  return 0;
}

//https://www.luogu.com.cn/problem/P3371

//4 6 1
//1 2 2
//2 3 2
//2 4 1
//1 3 5
//3 4 3
//1 4 4

//0 2 4 3
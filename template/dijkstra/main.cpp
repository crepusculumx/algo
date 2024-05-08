#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Edge {
  int v, w;
  Edge(int v1, int w1) : v(v1), w(w1) {}
};

struct Node {
  int id;
  int dis;
  Node(int id, int dis) : id(id), dis(dis) {}

  bool operator<(const Node &rhs) const {
    return dis < rhs.dis;
  }
  bool operator>(const Node &rhs) const {
    return rhs < *this;
  }
  bool operator<=(const Node &rhs) const {
    return !(rhs < *this);
  }
  bool operator>=(const Node &rhs) const {
    return !(*this < rhs);
  }
};

using Adj = vector<vector<Edge>>;
constexpr int INF = 0x3f3f3f3f;

vector<int> dijkstra(const Adj &adj, int s) {
  auto dis = vector<int>(adj.size(), INF);
  auto vis = vector<int>(adj.size(), false);
  auto q = priority_queue<Node, deque<Node>, greater<>>();

  dis[s] = 0;
  q.emplace(s, 0);

  while (!q.empty()) {
    auto [u, _] = q.top();
    q.pop();
    if (vis[u]) { continue; }
    vis[u] = true;
    for (const auto &[v, w] : adj[u]) {
      if (dis[u] + w < dis[v]) {
        dis[v] = dis[u] + w;
        q.emplace(v, dis[v]);
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
  auto dis = dijkstra(adj, s);
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
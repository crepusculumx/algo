#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Edge {
  int v, w;
  Edge(int v1, int w1) : v(v1), w(w1) {}
};

using Adj = vector<vector<Edge>>;
constexpr int INF = 0x3f3f3f3f;

vector<int> Spfa(const Adj &adj, int s) {
  auto dis = vector<int>(adj.size(), INF);
  auto in_que = vector<bool>(adj.size(), false);
  auto q = queue<int>();

  q.push(s);
  dis[s] = 0;
  in_que[s] = true;

  while (!q.empty()) {
    auto u = q.front();
    q.pop();
    in_que[u] = false;

    for (const auto &[v, w] : adj[u]) {
      if (dis[u] + w < dis[v]) {
        dis[v] = dis[u] + w;
        if (!in_que[v]) {
          q.push(v);
          in_que[v] = true;
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
  auto dis = Spfa(adj, s);
  for (auto &d : dis) {
    cout << (d == INF ? 0x7fffffff : d);
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
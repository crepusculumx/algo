#include <iostream>
#include <vector>
#include <functional>

using namespace std;

constexpr int MAX_N = 1e5 + 7;

class Solution {
 public:
  long long countPaths(int n, vector<vector<int>> &edges) {
    vector<bool> isPrime(MAX_N, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= n; ++i) {
      if (!isPrime[i]) { continue; }
      for (int j = i + i; j <= n; j += i) {
        isPrime[j] = false;
      }
    }

    vector<vector<int>> adj(n + 1);
    vector<int> colors(n + 1, 0);
    vector<int> colorCnt(n + 1, 0);
    int color = 1;
    for (const auto &edge : edges) {
      adj[edge[0]].push_back(edge[1]);
      adj[edge[1]].push_back(edge[0]);
    }

    function<void(int, int, int)> dfs = [&adj, &dfs, &colors, &isPrime](int cur, int fa, int color) {
      colors[cur] = color;
      for (const auto &v : adj[cur]) {
        if (v == fa) { continue; }
        if (isPrime[v]) { continue; }
        dfs(v, cur, color);
      }
      return;
    };

    for (int i = 1; i <= n; ++i) {
      if (!isPrime[i] && colors[i] == 0) { dfs(i, i, color++); }
    }
    for (int i = 1; i <= n; ++i) {
      colorCnt[colors[i]] += 1;
    }

    long long res = 0;

    for (int i = 1; i <= n; ++i) {
      if (!isPrime[i]) { continue; }
      long long curPath = 0;
      for (int l : adj[i]) {
        if (isPrime[l]) { continue; }

        res += colorCnt[colors[l]];
        res += curPath * colorCnt[colors[l]];
        curPath += colorCnt[colors[l]];
      }
    }
    return res;
  }
};

int main() {
  Solution s;
//  vector<vector<int>> v = {{1, 2}, {1, 3}, {2, 4}, {3, 5}, {3, 6}};
//  vector<vector<int>> v = {{1, 2}};
//  vector<vector<int>> v = {{1, 2}, {1, 4}, {4, 3}};
//  vector<vector<int>> v = {{1, 2}, {1, 3}, {2, 4}, {2, 5}};
  vector<vector<int>> v = {{1, 2}, {1, 8}, {2, 7}, {2, 6}, {2, 5}, {7, 4}, {6, 3}};
  cout << s.countPaths(8, v);
}
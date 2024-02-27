#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

constexpr int INF = 0x3f3f3f3f;

struct Point {
  int x;
  int y;

  Point(int x, int y) : x(x), y(y) {}

  bool operator<(const Point &rhs) const {
    if (x < rhs.x)
      return true;
    if (rhs.x < x)
      return false;
    return y < rhs.y;
  }
  bool operator>(const Point &rhs) const {
    return rhs < *this;
  }
  bool operator<=(const Point &rhs) const {
    return !(rhs < *this);
  }
  bool operator>=(const Point &rhs) const {
    return !(*this < rhs);
  }
};

struct Island {
  vector<Point> edges{};
  int w{0};
  int h{0};

  void minimize() {
    int l = INF;
    int r = 0;
    int u = INF;
    int d = 0;
    for (auto point : edges) {
      l = point.x < l ? point.x : l;
      r = point.x > r ? point.x : r;
      u = point.y < u ? point.y : u;
      d = point.y > d ? point.y : d;
    }

    for (auto &item : edges) {
      item.x -= l;
      item.y -= u;
    }
    w = r - l;
    h = d - u;

    sort(edges.begin(), edges.end());
  }

  [[nodiscard]] Island rotate() const {
    Island res;

    for (const auto &point : edges) {
      res.edges.emplace_back(h - point.y, point.x);
    }
    res.minimize();
    return res;
  }

  [[nodiscard]] Island reflect() const {
    Island res;

    for (const auto &point : edges) {
      res.edges.emplace_back(w - point.x, point.y);
    }
    res.minimize();
    return res;
  }

  string toString() {
    string res;
    for (const auto &item : edges) {
      res += static_cast<char>(item.x);
      res += static_cast<char>(item.y);
    }
    return res;
  }
};

class Solution {
 public:

  int numDistinctIslands2(vector<vector<int>> &grid) {
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {-1, 1, 0, 0};

    int n;
    int m;
    if (grid.empty()) { return 0; }
    n = static_cast<int>( grid.size());
    m = static_cast<int>(grid[0].size());

    int c = 1;
    vector<vector<int>> colorTable;
    colorTable.resize(grid.size(), vector<int>(grid[0].size(), 0));

    auto bfs = [&grid, &colorTable, &n, &m, &dx, &dy](Point s, int color) {

      queue<Point> q;
      q.push(s);
      colorTable[s.x][s.y] = color;

      while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i) {
          int x = cur.x + dx[i];
          int y = cur.y + dy[i];
          if (x < 0 || x >= n || y < 0 || y >= m) { continue; }
          if (grid[x][y] != 1) { continue; }
          if (colorTable[x][y] != 0) { continue; }
          q.emplace(x, y);
          colorTable[x][y] = color;
        }
      }
    };

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (grid[i][j] == 1 && colorTable[i][j] == 0) {
          bfs(Point{i, j}, c);
          ++c;
        }
      }
    }

    vector<Island> islands(c - 1);

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (grid[i][j] == 1) {
          islands[colorTable[i][j]-1].edges.emplace_back(i, j);
        }
      }
    }

    for (auto &island : islands) {
      island.minimize();
    }

    set<string> res_map;
    int res = 0;

    for (auto &island : islands) {
      auto r1 = island.toString();
      auto r2 = island.rotate().toString();
      auto r3 = island.rotate().rotate().toString();
      auto r4 = island.rotate().rotate().rotate().toString();
      auto r5 = island.reflect().toString();
      auto r6 = island.reflect().rotate().toString();
      auto r7 = island.reflect().rotate().rotate().toString();
      auto r8 = island.reflect().rotate().rotate().rotate().toString();

      if (res_map.count(r1) || res_map.count(r2) || res_map.count(r3) || res_map.count(r4) || res_map.count(r5)
          || res_map.count(r6)
          || res_map.count(r7) || res_map.count(r8)) {
        continue;
      }

      ++res;

      res_map.emplace(r1);
      res_map.emplace(r2);
      res_map.emplace(r3);
      res_map.emplace(r4);
      res_map.emplace(r5);
      res_map.emplace(r6);
      res_map.emplace(r7);
      res_map.emplace(r8);
    }

    return res;
  }
};
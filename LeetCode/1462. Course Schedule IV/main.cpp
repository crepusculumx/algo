#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
 private:
  static constexpr int N = 1e2 + 7;
  static constexpr int INF = 1e9;

  int d[N][N];
  int n;

  void floyd() {
    for (int k = 0; k < n; k++)
      for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
          d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
  }

 public:
  vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>> &prerequisites, vector<vector<int>> &queries) {
    n = numCourses;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (i == j) { d[i][j] = 0; }
        else { d[i][j] = INF; }
      }
    }

    for (const auto &item : prerequisites) {
      d[item[1]][item[0]] = 1;
    }

    floyd();

    vector<bool> ans;

    for (const auto &item : queries) {
      if (d[item[1]][item[0]] != INF) {
        ans.push_back(true);
      } else {
        ans.push_back(false);
      }
    }
    return ans;
  }
};

#include <iostream>
#include <unordered_set>
#include <vector>
#include <queue>

using namespace std;

class Solution {
private:
    int n;
    vector<vector<int>> adj{};
    vector<int> degree{};
    int res;

    void r(vector<int> &coins) {
        queue<int> q{};
        for (int u = 0; u < adj.size(); ++u) {
            if (degree[u] == 1 && !coins[u]) {
                q.push(u);
            }
        }

        while (!q.empty()) {
            auto u = q.front();
            q.pop();

            --degree[u];
            --res;
            for (const auto v: adj[u]) {
                --degree[v];
                if (degree[v] == 1 && !coins[v]) {
                    q.push(v);
                }
            }
        }
    }

    void rl() {
        vector<int> l{};
        for (int u = 0; u < adj.size(); ++u) {
            if (degree[u] == 1) {
                l.push_back(u);
            }
        }

        for (const auto &item: l) {
            auto u = item;

            --degree[u];
            --res;
            for (const auto v: adj[u]) {
                --degree[v];
            }
        }
    }

public:
    int collectTheCoins(vector<int> &coins, vector<vector<int>> &edges) {
        n = (int) coins.size();
        res = n;
        adj.resize(n);
        degree.resize(n);
        for (const auto &edge: edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
            ++degree[u];
            ++degree[v];
        }

        r(coins);

        rl();

        rl();

        if (res == 0) { return 0; }
        return (res - 1) * 2;
    }
};

int main() {
    Solution solution{};
    vector<int> coins{0, 0, 0, 1, 1, 0, 0, 1};
    vector<vector<int>> edges{{0, 1},
                              {0, 2},
                              {1, 3},
                              {1, 4},
                              {2, 5},
                              {5, 6},
                              {5, 7}};
    cout << solution.collectTheCoins(coins, edges);
    return 0;
}

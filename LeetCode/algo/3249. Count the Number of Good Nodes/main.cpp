#include <iostream>
#include <vector>

using namespace std;

class Solution {
    vector<vector<int> > adj;
    int ans = 0;

public:
    int dfs(int cur, int f) {
        int res = 1;
        bool eq = true;
        int lst = -1;
        for (int v: adj[cur]) {
            if (v == f) { continue; }
            int t = dfs(v, cur);
            res += t;
            if (lst != -1 && t != lst) { eq = false; }
            lst = t;
        }
        ans += eq;
        return res;
    }

    int countGoodNodes(vector<vector<int> > &edges) {
        adj.resize(edges.size() + 1);
        for (auto edge: edges) {
            adj[edge[0]].emplace_back(edge[1]);
            adj[edge[1]].emplace_back(edge[0]);
        }
        dfs(0, 0);
        return ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

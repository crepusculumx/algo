#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>
#include <unordered_map>

using namespace std;

struct pair_hash {
    template<class T1, class T2>
    size_t operator()(const pair<T1, T2> &p) const {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ (hash2 << 1);
    }
};

class Solution {
public:
    unordered_map<pair<int, int>, int, pair_hash> memo;

    int dfs(vector<int> &cuts, int l, int r) {
        if (memo.contains(make_pair(l, r))) {
            return memo[make_pair(l, r)];
        }
        int res = INT_MAX;
        for (const int cut: cuts) {
            if (!(cut > l && cut < r)) { continue; }
            auto cost = dfs(cuts, l, cut) + dfs(cuts, cut, r);
            if (cost < res) {
                res = cost;
            }
        }
        if (res == INT_MAX) { return memo[make_pair(l, r)] = 0; }
        return memo[make_pair(l, r)] = res + r - l;
    }

    int minCost(int n, vector<int> &cuts) {
        return dfs(cuts, 0, n);
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

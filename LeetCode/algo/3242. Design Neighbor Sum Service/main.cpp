#include <iostream>
#include <map>
#include <vector>

using namespace std;

class NeighborSum {
    int n;
    vector<vector<int> > &grid;
    map<int, pair<int, int> > pos;

public:
    NeighborSum(vector<vector<int> > &grid): grid(grid), n(grid.size()) {
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                pos[grid[i][j]] = make_pair(i, j);
            }
        }
    }

    int adjacentSum(int value) {
        int res = 0;
        int dx[] = {0, 0, -1, 1};
        int dy[] = {1, -1, 0, 0};
        auto [x, y] = pos[value];
        for (int i = 0; i < 4; i++) {
            if (x + dx[i] < n && y + dy[i] < n && x + dx[i] >= 0 && y + dy[i] >= 0) {
                res += grid[x + dx[i]][y + dy[i]];
            }
        }
        return res;
    }

    int diagonalSum(int value) {
        int res = 0;
        int dx[] = {-1, -1, 1, 1};
        int dy[] = {-1, 1, -1, 1};
        auto [x, y] = pos[value];
        for (int i = 0; i < 4; i++) {
            if (x + dx[i] < n && y + dy[i] < n && x + dx[i] >= 0 && y + dy[i] >= 0) {
                res += grid[x + dx[i]][y + dy[i]];
            }
        }
        return res;
    }
};

/**
 * Your NeighborSum object will be instantiated and called as such:
 * NeighborSum* obj = new NeighborSum(grid);
 * int param_1 = obj->adjacentSum(value);
 * int param_2 = obj->diagonalSum(value);
 */

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

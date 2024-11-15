#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minFlips(vector<vector<int> > &grid) {
        int ans1 = 0, ans2 = 0;
        for (auto &line: grid) {
            for (int i = 0; i < line.size(); i++) {
                if (line[i] != line[line.size() - 1 - i]) {
                    ans1++;
                }
            }
        }

        for (int i = 0; i < grid[0].size(); i++) {
            for (int j = 0; j < grid.size(); j++) {
                if (grid[j][i] != grid[grid.size() - 1 - j][i]) {
                    ans2++;
                }
            }
        }
        return min(ans1, ans2) / 2;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

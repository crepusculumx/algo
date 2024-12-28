#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isPossibleToSplit(vector<int> &nums) {
        unordered_map<int, int> s;
        for (int num: nums) {
            s.try_emplace(num, 0);
            s[num]++;
        }
        return !ranges::any_of(s, [](auto it) { return it.second > 2; });
    }
};

#include <iostream>

using namespace std;

class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int n = s.length();
        int l = 0, r = 0; //[l, r]
        int cnt[2] = {0, 0};
        int res = 0;
        for (int r = 0; r < n; r++) {
            cnt[s[r] - '0']++;
            while (cnt[0] > k && cnt[1] > k) {
                cnt[s[l] - '0']--;
                l++;
            }
            res += r - l + 1;
        }
        return res;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

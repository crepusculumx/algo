#include <algorithm>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool isSubstringPresent(string s) {
        unordered_set<string> table;
        for (int i = 0; i < s.length() - 1; ++i) {
            string t;
            t += s[i];
            t += s[i + 1];
            table.insert(t);
        }
        ranges::reverse(s);
        for (int i = 0; i < s.length() - 1; ++i) {
            string t;
            t += s[i];
            t += s[i + 1];
            if (table.contains(t)) {
                return true;
            }
        }
        return false;
    }
};

#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class WordDistance {
 public:

  unordered_map<string, vector<int>> m;

  WordDistance(vector<string> &wordsDict) {
    for (int i = 0; i < wordsDict.size(); ++i) {
      const auto &s = wordsDict[i];
      if (!m.contains(s)) { m[s] = vector<int>(); }
      m[s].push_back(i);
    }
  }

  int shortest(string word1, string word2) {
    int l1 = -0x3f3f3f3f;
    int l2 = -0x3f3f3f3f;

    int ans = 0x7fffffff;

    auto ps1 = m[word1];
    auto ps2 = m[word2];

    auto p1 = ps1.begin();
    auto p2 = ps2.begin();

    while (p1 != ps1.end() || p2 != ps2.end()) {
      if (p2 == ps2.end() || (p1 != ps1.end() && *p1 < *p2)) {
        l1 = *p1;
        ans = min(ans, *p1 - l2);
        ++p1;
      } else if (p1 == ps1.end() || (p2 != ps2.end() && *p2 < *p1)) {
        l2 = *p2;
        ans = min(ans, *p2 - l1);
        ++p2;
      }
    }

    return ans;
  }
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(wordsDict);
 * int param_1 = obj->shortest(word1,word2);
 */
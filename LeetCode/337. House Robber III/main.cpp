#include <iostream>
#include <map>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
 private:
  map<pair<TreeNode *, bool>, int> memo;

  int dfs(TreeNode *cur, bool can_rob) {
    if (cur == nullptr) { return 0; }
    if (memo.find(std::make_pair(cur, can_rob)) != memo.end()) {
      return memo.find(std::make_pair(cur, can_rob))->second;
    }
    int res = 0;
    if (can_rob) {
      res = max(res, cur->val + dfs(cur->left, false) + dfs(cur->right, false));
    }
    res = max(res, dfs(cur->left, true) + dfs(cur->right, true));
    memo.insert(std::make_pair(std::make_pair(cur, can_rob), res));
    return res;
  }

 public:
  int rob(TreeNode *root) {
    return dfs(root, true);
  }
};

int main() {
  std::cout << "Hello, World!" << std::endl;
  return 0;
}

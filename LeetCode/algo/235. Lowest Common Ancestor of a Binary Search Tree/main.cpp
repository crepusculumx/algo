#include <unordered_set>
#include <unordered_map>
#include <functional>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
 public:
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    auto f = unordered_map<TreeNode *, TreeNode *>();
    auto s = unordered_set<TreeNode *>();

    function<void(TreeNode *, TreeNode *)> dfs = [&dfs, &f](TreeNode *cur, TreeNode *fa) {
      if (cur == nullptr) { return; }
      f[cur] = fa;
      dfs(cur->left, cur);
      dfs(cur->right, cur);
    };

    dfs(root, root);

    do {
      s.emplace(p);
      p = f[p];
    } while (p != root);

    do {
      if (s.contains(q)) { return q; }
      q = f[q];
    } while (q != root);

    return root;
  }
};
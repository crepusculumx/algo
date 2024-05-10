#include <iostream>
#include <unordered_map>

using namespace std;

struct TrieNode {
  int cnt = 0;
  unordered_map<char, TrieNode *> children{};
};

class Trie {
 private:
  TrieNode *head = new TrieNode;

  template<typename It>
  void insert(It begin, It end, TrieNode *cur_node) {
    cur_node->cnt++;
    if (begin == end) {
      return;
    }
    char c = *begin;
    if (!cur_node->children.contains(c)) {
      cur_node->children[c] = new TrieNode;
    }
    insert(begin + 1, end, cur_node->children[c]);
  }

  template<typename It>
  int find(It begin, It end, TrieNode *cur_node) {
    char c = *begin;
    if (begin == end) { return cur_node->cnt; }
    if (!cur_node->children.contains(c)) { return 0; }
    return find(begin + 1, end, cur_node->children[c]);
  }

  void destroy(TrieNode *cur_node) {
    for (const auto &[_, nxt] : cur_node->children) {
      destroy(nxt);
    }
    delete cur_node;
  }

 public:
  template<typename It>
  void insert(It begin, It end) {
    insert(begin, end, head);
  }

  template<typename It>
  int find(It begin, It end) {
    return find(begin, end, head);
  }

  ~Trie() {
    destroy(head);
  }
};

int main() {
  int T;
  cin >> T;
  while (T--) {
    int n, q;
    cin >> n >> q;
    auto trie = Trie{};
    for (int i = 0; i < n; ++i) {
      string s;
      cin >> s;
      trie.insert(s.begin(), s.end());
    }

    for (int i = 0; i < q; ++i) {
      string s;
      cin >> s;
      cout << trie.find(s.begin(), s.end()) << endl;
    }
  }
  return 0;
}

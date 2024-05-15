#include <iostream>
#include <vector>

class DisjointSetUnion {
 private:
  struct Node {
    size_t parent;
    int size;
    Node() = default;
    Node(size_t parent, int size) : parent(parent), size(size) {}
  };

  using Dsu = std::vector<Node>;

  Dsu dsu;

  void UniteBySize(size_t x, size_t y) {
    auto px = Find(x);
    auto py = Find(y);

    if (dsu[px].size > dsu[py].size) { std::swap(px, py); }

    dsu[px].parent = py;
    dsu[py].size += dsu[px].size;
  }

 public:
  explicit DisjointSetUnion(size_t n) {
    Resize(n);
  }

  void Resize(size_t n) {
    dsu = Dsu(n);
    Clear();
  }

  void Clear() {
    for (int i = 0; i < dsu.size(); ++i) {
      dsu[i] = Node(i, 1);
    }
  }

  void Unite(size_t x, size_t y) {
    return UniteBySize(x, y);
  }

  size_t Find(size_t cur) { // NOLINT(*-no-recursion)
    if (dsu[cur].parent == cur) { return cur; }
    dsu[cur].parent = Find(dsu[cur].parent);
    dsu[cur].size = 1;
    return dsu[cur].parent;
  }

};

int main() {
  int N, M;
  std::cin >> N >> M;

  auto dsu = DisjointSetUnion(N);

  for (int i = 0; i < M; ++i) {
    int z, x, y;
    std::cin >> z >> x >> y;
    x--;
    y--;
    if (z == 1) {
      dsu.Unite(x, y);
    } else {
      if (dsu.Find(x) == dsu.Find(y)) {
        std::cout << "Y" << std::endl;
      } else {
        std::cout << "N" << std::endl;
      }
    }
  }
  return 0;
}

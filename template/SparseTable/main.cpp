#include <iostream>
#include <vector>
#include <cmath>
#include <functional>

template<typename T>
class SparseTable {
 public:
  using VT = std::vector<T>;
  using VVT = std::vector<VT>;
  using func_type = std::function<T(const T &, const T &)>;

 private:
  size_t n;
  VVT st;

  static T default_func(const T &t1, const T &t2) { return std::max(t1, t2); }
  func_type op;

  void pre() {
    for (size_t j = 1; j < (size_t) std::log2(n) + 1; ++j) {
      for (size_t i = 0; i + (1 << j) - 1 < n; ++i) {
        st[i][j] = op(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
      }
    }
  }

 public:
  SparseTable(const VT &v, func_type func = default_func) : op(std::move(func)), n(v.size()) {
    st.reserve(n);
    for (const auto &item : v) {
      auto temp = VT((size_t) log2(n) + 1);
      temp[0] = item;
      st.template emplace_back(std::move(temp));
    }

    pre();
  }

  T query(size_t l, size_t r) {
    auto k = static_cast<size_t>(std::log2(r - l + 1));
    return op(st[l][k], st[r - (1 << k) + 1][k]);
  }
};

int main() {
  // https://www.luogu.com.cn/problem/P3865
  int N, M;
  std::cin >> N >> M;

  using std::vector;
  using std::cin;
  using std::cout;
  using std::endl;

  vector<int> v(N);

  for (int i = 0; i < N; ++i) {
    cin >> v[i];
  }

  SparseTable<int> st(v);

  for (int i = 0; i < M; ++i) {
    int l, r;
    cin >> l >> r;
    l--;
    r--;
    cout << st.query(l, r) << endl;
  }
}

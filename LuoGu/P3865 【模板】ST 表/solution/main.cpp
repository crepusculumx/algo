#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

inline int read() {
  char c = getchar();
  int x = 0, f = 1;
  while (c < '0' || c > '9') {
    if (c == '-')f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = x * 10 + c - '0';
    c = getchar();
  }
  return x * f;
}

constexpr int MAX_N = 1e6 + 7;

int N, M;
int st[MAX_N][26];

void pre() {
  for (size_t j = 1; j < (size_t) log2(N) + 1; ++j) {
    for (size_t i = 0; i + (1 << j) - 1 < N; ++i) {
      st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
    }
  }
}
int query(size_t l, size_t r) {
  auto k = static_cast<size_t>(log2(r - l + 1));
  return std::max(st[l][k], st[r - (1 << k) + 1][k]);
}

int main() {
  N = read();
  M = read();

  for (int i = 0; i < N; ++i) {
    st[i][0] = read();
  }

  pre();

  for (int i = 0; i < M; ++i) {
    int l, r;
    l = read();
    r = read();
    l--;
    r--;
    printf("%d\n", query(l, r));
  }
  return 0;
}

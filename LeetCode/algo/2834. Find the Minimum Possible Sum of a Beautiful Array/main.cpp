class Solution {
 public:
  int minimumPossibleSum(int n, int target) {
    constexpr int MOD = 1e9 + 7;

    if (n == 1) { return 1; }
    int m = target / 2;
    if (n <= m) {
      return (long long) (1 + n) * n / 2 % MOD;
    } else {
      return ((long long) (1 + m) * m / 2 +
          ((long long) target + target + (n - m) - 1) * (n - m) / 2) % MOD;
    }
  }
};
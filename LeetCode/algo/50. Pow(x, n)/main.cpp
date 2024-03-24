#include <iostream>

class Solution {
 public:

  double pow(double x, long n) {
    if (n == 0) { return 1; }
    bool flag = false;
    if (n < 0) {
      n = -n;
      flag = true;
    }
    auto temp = pow(x, n / 2);
    auto res = temp * temp * (n % 2 == 1 ? x : 1);
    return flag ? 1 / res : res;
  }

  static double pow2(double x, long n) {
    bool flag = false;
    if (n < 0) {
      n = -n;
      flag = true;
    }

    double ans = 1.0;
    double w = x;
    while (n > 0) {
      if (n & 1) {
        ans *= w;
      }
      w *= w;
      n >>= 1;
    }
    return flag ? 1 / ans : ans;
  }

  double myPow(double x, int n) {
    return pow2(x, n);
  }
};

int main() {
  std::cout << "Hello, World!" << std::endl;
  return 0;
}

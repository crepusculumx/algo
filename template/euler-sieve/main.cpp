#include <bitset>
#include <iostream>
#include <vector>

using namespace std;

template <size_t kMaxN>
class EulerSieve {
  bitset<kMaxN> isPrime{};
  vector<int> primes{};

 public:
  EulerSieve() {
    isPrime.flip();
    isPrime[0] = isPrime[1] = 0;
    for (int i = 2; i < kMaxN; i++) {
      if (isPrime[i]) {
        primes.emplace_back(i);
      }

      for (const int prime : primes) {
        if (i * prime >= kMaxN) {
          break;
        }
        isPrime[i * prime] = 0;
        if (i % prime == 0) {
          break;
        }
      }
    }
  }

  int IsPrime(int num) { return isPrime[num]; }

  [[nodiscard]] int KthPrime(int k) const { return primes[k - 1]; }
};

EulerSieve<static_cast<size_t>(1e8 + 7)> euler_sieve;

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  int n, q;
  cin >> n >> q;

  while (q--) {
    int k;
    cin >> k;
    printf("%d\n", euler_sieve.KthPrime(k));
  }
  return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

long long fpow(long long b, long long p, long long k) //b ^ p % k;
{
    if (p == 0) return 1 % k;
    long long temp = fpow(b, p / 2, k);
    long long ans = temp * temp % k;
    if (p % 2 != 0) ans *= b;
    return ans % k;
}

class Solution {
public:
    vector<int> getFinalState(vector<int> &nums, int k, int multiplier) {
        if (multiplier == 1) {
            return nums;
        }
        const long long n = nums.size();
        constexpr long long mod = 1e9 + 7;
        const auto mx = *ranges::max_element(nums);
        priority_queue<pair<long long, int>, vector<pair<long long, int> >, greater<> > q;
        for (int i = 0; i < nums.size(); i++) {
            q.emplace(nums[i], i);
        }
        for (; q.top().first < mx && k != 0; k--) {
            auto temp = q.top();
            q.pop();
            temp.first *= multiplier;
            q.emplace(temp);
        }
        for (int i = 0; i < n; i++) {
            const long long t = k / n + (i < (k % n));
            nums[q.top().second] = static_cast<int>((q.top().first % mod) * fpow(multiplier, t, mod) % mod);
            q.pop();
        }
        return nums;
    }
};

import static java.lang.Math.max;

class Solution {
    public int maximumScore(int[] nums, int k) {
        int l = k - 1;
        int r = k + 1;

        int cur = nums[k];
        int res = 0;
        for (int i = nums[k]; i >= 0; i--) {
            while (l >= 0 && nums[l] >= i) {
                --l;
            }
            while (r < nums.length && nums[r] >= i) {
                ++r;
            }
            res = max(res, (r - l - 1) * i);
            if (l == -1 && r == nums.length) {
                break;
            }
        }
        return res;
    }
}

public class Main {
}

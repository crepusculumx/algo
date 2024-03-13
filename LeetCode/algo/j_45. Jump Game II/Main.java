import java.util.Arrays;

import static java.lang.Math.min;

class Solution {

    int dfs(int[] nums, int p, int[] memo) {
        if (p == nums.length - 1) {
            return 0;
        }
        if (memo[p] != -1) {
            return memo[p];
        }
        int res = 0x7fffffff;
        for (int i = p + 1; i <= p + nums[p]; i++) {
            if (i >= nums.length) {
                break;
            }
            res = min(res, dfs(nums, i, memo));
        }
        return memo[p] = res + 1;
    }

    public int jump(int[] nums) {
        int[] memo = new int[nums.length];
        Arrays.fill(memo, -1);
        return dfs(nums, 0, memo);
    }
}

public class Main {
    public static void main(String[] args) {

    }
}

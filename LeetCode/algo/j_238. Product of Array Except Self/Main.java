class Solution {
    public int[] productExceptSelf(int[] nums) {
        var n = nums.length;
        var l = new int[n];
        var r = new int[n];

        l[0] = nums[0];
        r[n - 1] = nums[n - 1];

        for (int i = 1; i < n; i++) {
            l[i] = l[i - 1] * nums[i];
        }

        for (int i = n - 1 - 1; i >= 0; i--) {
            r[i] = r[i + 1] * nums[i];
        }

        var res = new int[n];
        res[0] = r[1];
        res[n - 1] = l[n - 2];

        for (int i = 1; i < n - 1; i++) {
            res[i] = l[i - 1] * r[i + 1];
        }
        return res;
    }
}

public class Main {
}

import static java.lang.Math.max;

class Solution {

    public boolean canJump(int[] nums) {
        int nxt = nums[0];
        for (int i = 0; i < nums.length; i++) {
            if (i > nxt) {
                return false;
            }
            nxt = max(nxt, nums[i] + i);
            if (nxt >= nums.length - 1) {
                return true;
            }
        }
        return true;
    }
}

public class Main {
    public static void main(String[] args) {

    }
}

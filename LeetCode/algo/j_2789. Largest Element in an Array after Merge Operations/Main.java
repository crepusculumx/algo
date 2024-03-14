import java.util.ArrayList;
import java.util.Arrays;
import java.util.stream.Collectors;

class Solution {
    public long maxArrayValue(int[] nums) {
        var arr = Arrays.stream(nums)
                .mapToLong(value -> (long) value)
                .boxed()
                .collect(Collectors.toList());

        for (int i = nums.length - 1; i > 0; i--) {
            if (arr.get(i) >= arr.get(i - 1)) {
                arr.set(i - 1, arr.get(i) + arr.get(i-1));
            }
        }
        return arr.stream().mapToLong(Long::longValue).max().orElse(Long.MIN_VALUE);
    }
}

public class Main {
    public static void main(String[] args) {

    }
}

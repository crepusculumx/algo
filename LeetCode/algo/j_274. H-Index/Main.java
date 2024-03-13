import java.util.Arrays;

class Solution {
    public int hIndex(int[] citations) {
        Arrays.sort(citations);

        int ans = 0;
        int p = 0;
        for (int i = 0; i < 5000; i++) {
            while (p < citations.length && citations[p] < i) {
                ++p;
            }
            if (p == citations.length) {
                break;
            }
            if (citations.length - p >= i) {
                ans = i;
            }
        }
        return ans;
    }
}

public class Main {
}

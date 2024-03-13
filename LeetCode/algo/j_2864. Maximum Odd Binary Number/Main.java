class Solution {
    public String maximumOddBinaryNumber(String s) {
        var res = new StringBuilder();
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '1') {
                res.append('1');
            }
        }
        res.deleteCharAt(-1);
        while (res.length() < s.length() - 1) {
            res.append('0');
        }
        res.append('1');
        return res.toString();
    }
}

public class Main {
    public static void main(String[] args) {
        Solution s = new Solution();
    }
}

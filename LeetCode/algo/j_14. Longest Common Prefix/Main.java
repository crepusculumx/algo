import java.util.Arrays;

class Solution {
    public String longestCommonPrefix(String[] strs) {
        StringBuilder res = new StringBuilder();
        int minL = Arrays.stream(strs).map(String::length).min(Integer::compare).orElse(0);

        for (int i = 0; i < minL; i++) {
            char c = strs[0].charAt(i);
            for (int j = 1; j < strs.length; j++) {
                if (strs[j].charAt(i) != c) {
                    return res.toString();
                }
            }
            res.append(c);
        }
        return res.toString();
    }
}

public class Main {
}

class Solution {
    public int lengthOfLastWord(String s) {
        int p = s.length() - 1;
        while (s.charAt(p) == ' ') {
            --p;
        }

        int res = 0;
        while (p >= 0 && s.charAt(p) != ' '){
            --p;
            ++res;
        }

        return res;
    }
}

public class Main {
}

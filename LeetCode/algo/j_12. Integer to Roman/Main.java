import java.util.ArrayList;

class Solution {
    private static class Pair {
        String str;
        int num;

        public Pair(String str, int num) {
            this.str = str;
            this.num = num;
        }
    }

    public String intToRoman(int num) {
        var pairs = new ArrayList<Pair>();
        pairs.add(new Pair("M", 1000));
        pairs.add(new Pair("CM", 900));
        pairs.add(new Pair("D", 500));
        pairs.add(new Pair("CD", 400));
        pairs.add(new Pair("C", 100));
        pairs.add(new Pair("XC", 90));
        pairs.add(new Pair("L", 50));
        pairs.add(new Pair("XL", 40));
        pairs.add(new Pair("X", 10));
        pairs.add(new Pair("IX", 9));
        pairs.add(new Pair("V", 5));
        pairs.add(new Pair("IV", 4));
        pairs.add(new Pair("I", 1));

        StringBuilder s = new StringBuilder();

        for (Pair pair : pairs) {
            if (num / pair.num > 0) {
                s.append(String.valueOf(pair.str).repeat(Math.max(0, num / pair.num)));
                num %= pair.num;
            }
        }
        return s.toString();
    }
}

public class Main {
}

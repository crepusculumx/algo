import static java.lang.Math.max;

class Solution {

    private int N;

    private int[] memo;

    public int dfs(int cur, int[] ratings) {
        if (memo[cur] != -1) {
            return memo[cur];
        }
        int res = 0;
        if (cur - 1 >= 0 && ratings[cur] > ratings[cur - 1]) {
            res = max(res, dfs(cur - 1, ratings));
        }
        if (cur + 1 < N && ratings[cur] > ratings[cur + 1]) {
            res = max(res, dfs(cur + 1, ratings));
        }
        return memo[cur] = res + 1;
    }


    public int candy(int[] ratings) {
        N = ratings.length;

        memo = new int[N];
        for (int i = 0; i < N; i++) {
            memo[i] = -1;
        }

        for (int i = 0; i < N; i++) {
            dfs(i, ratings);
        }

        int res = 0;
        for (int i : memo) {
            res += i;
        }
        return res;
    }
}

public class Main {
}

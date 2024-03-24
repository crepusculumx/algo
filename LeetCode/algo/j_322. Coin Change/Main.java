import java.util.HashMap;
import java.util.Map;

import static java.lang.Math.min;

class Solution {

    private final int INF = 0x7f7f7f7f;
    private final Map<Integer, Integer> memo = new HashMap<>();

    private int minRes = INF;

    private int dfs(int[] coins, int amount) {
        if (amount == 0) {
            return 0;
        }
        if (memo.containsKey(amount)) {
            return memo.get(amount);
        }
        int res = INF;
        for (int coin : coins) {
            if (coin <= amount) {
                res = min(res, dfs(coins, amount - coin));
            }
        }
        res = res == INF ? INF : res + 1;
        memo.put(amount, res);
        return res;
    }

    public int coinChange(int[] coins, int amount) {
        var res = dfs(coins, amount);
        return res == INF ? -1 : res;
    }
}

public class Main {
}

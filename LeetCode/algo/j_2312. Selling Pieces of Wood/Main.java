import java.util.*;

import static java.lang.Math.max;

class Wood {
    int x, y;

    public Wood(int x, int y) {
        this.x = x;
        this.y = y;
    }


    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Wood pos = (Wood) o;
        return x == pos.x && y == pos.y;
    }

    @Override
    public int hashCode() {
        return Objects.hash(x, y);
    }
}

class Solution {

    private final Map<Wood, Integer> map = new HashMap<>();
    private final long[][] memo = new long[200 + 7][200 + 7];

    public long dfs(int m, int n) {
        var wood = new Wood(m, n);
        if (memo[m][n] != -1) {
            return memo[m][n];
        }

        long res = 0;
        if (map.containsKey(wood)) {
            res = map.get(wood);
        }

        if (m == 1 && n == 1) {
            return res;
        }

        for (int i = 1; i < m; i++) {
            res = max(res, dfs(i, n) + dfs(m - i, n));
        }
        for (int i = 1; i < n; i++) {
            res = max(res, dfs(m, i) + dfs(m, n - i));
        }
        memo[m][n] = res;
        return res;
    }

    public long sellingWood(int m, int n, int[][] prices) {
        for (var rol : memo) {
            Arrays.fill(rol, -1);
        }

        for (int[] price : prices) {
            map.put(new Wood(price[0], price[1]), price[2]);
        }
        return dfs(m, n);
    }
}

public class Main {
    public static void main(String[] args) {
//        Solution s = new Solution();
//        int[][] prices = {
//                {1, 1, 1},
//                {1, 1, 1}
//        };
//        s.sellingWood(200, 200, prices);
    }
}

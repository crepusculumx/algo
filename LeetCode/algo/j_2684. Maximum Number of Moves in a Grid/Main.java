import java.util.Arrays;

import static java.lang.Math.max;

class Solution {

    int[][] memo;
    int[] dx = {-1, 0, 1};
    int[] dy = {1, 1, 1};

    int n, m;

    private int dfs(int[][] grid, int x, int y) {
        if (y == m - 1) {
            return 1;
        }
        if (memo[x][y] != -1) {
            return memo[x][y];
        }
        int res = 0;
        for (int i = 0; i < 3; i++) {
            int tx = dx[i] + x;
            int ty = dy[i] + y;
            if (tx < 0 || ty < 0 || tx >= n || ty >= m) {
                continue;
            }
            if (grid[tx][ty] <= grid[x][y]) {
                continue;
            }
            res = max(res, dfs(grid, tx, ty));
        }
        return memo[x][y] = res + 1;
    }

    public int maxMoves(int[][] grid) {
        n = grid.length;
        m = grid[0].length;
        memo = new int[grid.length][grid[0].length];
        for (int[] item : memo) {
            Arrays.fill(item, -1);
        }

        int res = 0;
        for (int i = 0; i < n; i++) {
           res = max(res, dfs(grid, i, 0));
        }
        return res - 1;
    }
}

public class Main {
}

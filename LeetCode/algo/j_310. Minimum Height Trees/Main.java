import java.util.*;

class Solution {
    private int N = 0;
    private final List<List<Integer>> adj = new ArrayList<>();

    public int findL(int s, List<Integer> fa) {
        for (int i = 0; i < N; i++) {
            fa.set(i, -1);
        }
        fa.set(s, s);

        var q = new ArrayDeque<Integer>();
        q.add(s);

        int res = s;
        while (!q.isEmpty()) {
            var cur = q.poll();
            res = cur;

            for (Integer v : adj.get(cur)) {
                if (fa.get(cur).equals(v)) {
                    continue;
                }
                fa.set(v, cur);
                q.add(v);
            }
        }
        return res;
    }

    public List<Integer> findMinHeightTrees(int n, int[][] edges) {
        N = n;
        for (int i = 0; i < n; i++) {
            adj.add(new ArrayList<>());
        }

        for (int[] edge : edges) {
            adj.get(edge[0]).add(edge[1]);
            adj.get(edge[1]).add(edge[0]);
        }

        var fa = new ArrayList<Integer>();
        for (int i = 0; i < n; i++) {
            fa.add(-1);
        }
        int l = findL(0, fa);
        int r = findL(l, fa);

        List<Integer> path = new ArrayList<Integer>();
        var res = new ArrayList<Integer>();
        int cur = r;
        while (true) {
            path.add(cur);
            if (cur == fa.get(cur)) {
                break;
            }
            cur = fa.get(cur);
        }
        int m = path.size();
        if (m % 2 == 0) {
            res.add(path.get(m / 2 - 1));
        }
        res.add(path.get(m / 2));
        return res;
    }
}

public class Main {
    public static void main(String[] args) {
    }
}

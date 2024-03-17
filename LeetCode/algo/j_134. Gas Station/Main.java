class Solution {
    public int canCompleteCircuit(int[] gas, int[] cost) {
        int n = gas.length;
        int s = 0;
        int cur = 0;
        int curGas = 0;
        int cnt = 0;
        while (true) {
            cnt++;
            if (cnt > n * 3) {
                return -1;
            }
            curGas += gas[cur];
            if (curGas < cost[cur]) {
                cur = (cur + 1) % n;
                s = cur;
                curGas = 0;
            } else {
                curGas -= cost[cur];
                cur = (cur + 1) % n;
                if (cur == s) {
                    break;
                }
            }
        }
        return cur;
    }
}

public class Main {
}

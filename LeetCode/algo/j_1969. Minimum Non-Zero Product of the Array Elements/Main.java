class Solution {

    public long pow(long x, long n, long mod) {
        if (n == 1) {
            return x;
        }
        long temp = pow(x, n / 2, mod);
        if(n % 2 == 1){
            return temp * temp * x % mod;
        }else{
            return temp * temp % mod;
        }
    }

    public int minNonZeroProduct(int p) {
        if (p == 1) {
            return 1;
        }
        long mod = 1000000007;
        long x = pow(2, p, mod) - 1;
        long y = (long) 1 << (p - 1);
        return (int) (pow(x - 1, y - 1, mod) * x % mod);
    }
}

public class Main {
}

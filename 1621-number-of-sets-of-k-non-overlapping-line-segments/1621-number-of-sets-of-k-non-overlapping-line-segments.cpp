class Solution {
private:
    long long power(long long base, long long exp) {
        long long res = 1;
        base %= 1000000007;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % 1000000007;
            base = (base * base) % 1000000007;
            exp /= 2;
        }
        return res;
    }

    long long modInverse(long long n) {
        return power(n, 1000000007 - 2);
    }

public:
    int numberOfSets(int n, int k) {
        long long MOD = 1e9 + 7;
        
        // We need to compute C(n + k - 1, 2k) % MOD
        int N = n + k - 1;
        int R = 2 * k;

        if (R > N) return 0;

        long long numerator = 1;
        long long denominator = 1;

        for (int i = 0; i < R; i++) {
            numerator = (numerator * (N - i)) % MOD;
            denominator = (denominator * (i + 1)) % MOD;
        }

        return (numerator * modInverse(denominator)) % MOD;
    }
};
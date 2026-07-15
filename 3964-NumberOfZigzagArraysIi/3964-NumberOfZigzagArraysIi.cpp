// Last updated: 7/15/2026, 6:36:46 PM
class Solution {
public:
    static const long long MOD = 1e9 + 7;

    using Matrix = vector<vector<long long>>;

    Matrix multiply(Matrix &A, Matrix &B) {
        int n = A.size();
        Matrix C(n, vector<long long>(n, 0));

        for (int i = 0; i < n; i++) {
            for (int k = 0; k < n; k++) {
                if (A[i][k] == 0) continue;

                for (int j = 0; j < n; j++) {
                    C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
                }
            }
        }

        return C;
    }

    Matrix power(Matrix base, long long exp) {
        int n = base.size();
        Matrix res(n, vector<long long>(n, 0));

        for (int i = 0; i < n; i++) res[i][i] = 1;

        while (exp > 0) {
            if (exp & 1) res = multiply(res, base);
            base = multiply(base, base);
            exp >>= 1;
        }

        return res;
    }

    vector<long long> apply(Matrix &M, vector<long long> &v) {
        int n = M.size();
        vector<long long> res(n, 0);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                res[i] = (res[i] + M[i][j] * v[j]) % MOD;
            }
        }

        return res;
    }

    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;

        if (n == 1) return m;

        int size = 2 * m;

        vector<long long> base(size, 0);

        for (int i = 0; i < m; i++) {
            base[i] = i;             // ending at i, last move up
            base[m + i] = m - 1 - i; // ending at i, last move down
        }

        if (n == 2) {
            long long ans = 0;
            for (long long x : base) ans = (ans + x) % MOD;
            return ans;
        }

        Matrix T(size, vector<long long>(size, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                if (j < i) {
                    T[i][m + j] = 1; 
                }

                if (j > i) {
                    T[m + i][j] = 1;
                }
            }
        }

        Matrix P = power(T, n - 2);
        vector<long long> finalDP = apply(P, base);

        long long ans = 0;
        for (long long x : finalDP) {
            ans = (ans + x) % MOD;
        }

        return ans;
    }
};
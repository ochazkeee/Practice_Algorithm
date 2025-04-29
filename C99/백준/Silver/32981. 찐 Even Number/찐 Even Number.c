#include <stdio.h>
#define MOD 1000000007
long long mod_pow(long long base,long long exp) {
    long long result = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % MOD;
        }
        base = (base * base) % MOD;
        exp = exp / 2;
    }
    return result;
}
int main() {
    int Q;
    int N;
    long result=1;

    scanf("%d", &Q);
    getchar();

    for (int i = 0; i < Q; i++) {
        scanf("%d", &N);
        getchar();

        if (N == 1) {
            printf("5\n");
        }
        else {
            long long result = (4*mod_pow(5,N-1))%MOD;
            printf("%lld\n", result);
        }
    }
    return 0;
}
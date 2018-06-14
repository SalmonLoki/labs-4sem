#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;
long long n, x;
long h = 0;
const int SQRT_MAX_N = 100000;
const int S = 10000;
bool nprime[SQRT_MAX_N], bl[S];
int primes[SQRT_MAX_N], cnt;

int main() {
    ios::sync_with_stdio(0);

    cin >> n;
    cin >> x;

    int nsqrt = (int) sqrt (n + .0);
    for (int i = 2; i <= nsqrt; ++i)
        if (!nprime[i]) {
            primes[cnt++] = i;
            if (i * 1ll * i <= nsqrt)
                for (int j=i*i; j<=nsqrt; j+=i)
                    nprime[j] = true;
        }


    long long maxk = n/S;
    for (int k = 0; k<=maxk; ++k) {
        memset (bl, 0, sizeof bl);
        int start = k * S;
        for (int i=0; i<cnt; ++i) {
            int start_idx = (start + primes[i] - 1) / primes[i];
            int j = max(start_idx,2) * primes[i] - start;
            for (; j<S; j+=primes[i])
                bl[j] = true;
        }
        if (k == 0)
            bl[0] = bl[1] = true;
        for (int i=0; i<S && start+i<=n; ++i)
            if (!bl[i])
                h = h * x + i;
    }

    cout << h;
    return 0;
}
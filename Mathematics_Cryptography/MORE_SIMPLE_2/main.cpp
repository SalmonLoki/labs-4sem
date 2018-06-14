#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>

using  namespace std;

const long long  MAX_N = 1000000000ll;
const int blockSize = 1000;
bool nprime [MAX_N];
bool block[blockSize];
long long primes [MAX_N];
long long  n, x;
int cnt = 0;

int main() {
    ios::sync_with_stdio(0);

    cin >> n;
    cin >> x;
    long h = 0ll;


    for (long long i = 2ll; i * i <= n; i++)
        if (!nprime[i]) {
            primes[cnt++] = i;
            if (i * i * 1ll * (i * i) <= n)
                for (long long j = i * i; j * j <= n; j += i)
                    nprime[j] = true;
        }

    long long maxk =  n/blockSize;
    long long start, startInd, j;
    for (long long  k = 0ll; k <= maxk; k++) {

        for (bool &i : block) i = false;

        start = k * blockSize;
        for (long long i = 0ll; i < cnt; i++) {
            startInd = (start + primes[i] - 1) / primes[i];
            j = max(startInd, 2ll) * primes[i] - start;
            for (; j < blockSize; j += primes[i])
                block[j] = true;
        }
        if (k == 0)
            block[0] = block[1] = true;
        for (int i = 0; i < blockSize && start + i <= n; ++i)
            if (!block[i])
                h = h * x + i;

    }


    cout << h;
    return 0;
}
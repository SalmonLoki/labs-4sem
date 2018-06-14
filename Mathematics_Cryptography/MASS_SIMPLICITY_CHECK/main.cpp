#include <iostream>
#include <cstdio>
#include <vector>
using  namespace std;

unsigned long N = 1000000; // 2 <= a <= 10^6;
//char *prime = new char[N + 1];
vector<char> prime (N + 1, true);

bool is_simple(int a) {
    return prime[a];
}

static void createSieveOfEratosthenes(){
    prime[0] = false;
    prime[1] = false;

    for (int i = 2; i * i <= N; i++)
        if (prime[i])
            if (i * i * 1ll <= N)
                for (int j = i*i; j <= N; j += i)
                    prime[j] = false;
}

int main() {
    ios::sync_with_stdio(0);
    createSieveOfEratosthenes();

    int n, a;
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        //cin >> a;
        //cout << (is_simple(a) ? "YES" : "NO") << '\n';

        scanf("%d", &a);
        printf("%s\n", (is_simple(a) ? "YES" : "NO"));
    }
    return 0;
}
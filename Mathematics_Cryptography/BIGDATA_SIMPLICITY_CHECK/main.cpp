#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>

using  namespace std;

long long gcd (long long a, long long b) {
    return b ? gcd (b, a % b) : a;
}


const long long maxlong = 4e18;
// Переводит число a в форму q * 2^p
void transform_num ( long long n, long long &p, long long &q){
    p = 0ll;
    q = n;
    while (q % 2 == 0) {
        p++;
        q /= 2;
    }
}


long long b;
bool is_simple(long long a) {
    if (a == 2)
        return true;
    if (a < 2 || a % 2 == 0)
        return false;

    // Переводит число a-1 = q * 2^p
    long long p, q;
    transform_num (a - 1, p, q);
    //printf("%d -1 = %d  * 2^ %d \n", a, q, p);


    //b - потенциальный свидетель простоты a (1 < b < a)
    // проверяем, что a и b взаимно просты (иначе это приведет к ошибке)
    // если они не взаимно просты, то либо n не просто, либо нужно увеличить b
    /*b = 2ll;
    for (long long g = 0; (g = gcd(a, b)) != 1; b++) {
        cout << "0";
        if (a > g) //if (a > b)
            return false;
    }*/
   // b = (0ll + rand() + (rand() << 32ll)) % min(maxlong/a, a-2);
    //b = rand() % (a-2);
    //b = (0ll + rand() + (rand() << 32ll)) % (a-2);
    b = abs(7 * (rand())) % (a - 2);
    if(b <= 1) b = 2;
    if (b < 2)
        return true;


    // вычисляем b^q mod a, если оно равно 1 или a-1, то a простое (или псевдопростое)
    //Вычисляет rem = b^q (mod a)
    //rem = pow (b, q);
    //long long rem = long_pow(b, q, a);
    long long rem = 1ll;
    while (q > 0) {
        if (q & 1)
            rem *= b;

        b*=b;
        b %= a;
        rem %= a;

        q /= 2;
    }


    if (rem == 1ll || rem == a - 1ll)
        return true;


    // теперь вычисляем b^2q, b^4q, ... , b^((a-1)/2)
    // если какое-либо из них равно a-1, то a простое (или псевдопростое)
    for (long long i = 1; i < p; i++) {
        // Умножает rem *= rem (mod a)
        rem *= rem;
        rem %= a;
        if (rem == a - 1)
            return true;
        if (rem == 1)
            return false;
    }
    return false;
}


int main() {
    ios::sync_with_stdio(0);

    int n;
    long long a;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a;
        bool fl = true;

        for (int j = 0; j < 20 ; j++)
            if (!is_simple(a)){

                fl = false;
                break;
            }
        cout << (fl ? "YES" : "NO") << endl;
    }
    return 0;
}
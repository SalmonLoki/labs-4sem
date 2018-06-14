#include <iostream>
#include <fstream>
#include <vector>
#include <deque>
#include <climits>

using namespace std;
long long INF = LONG_LONG_MAX;

int n;
long long C[301][301]; // 2 <= n <= 300
vector<int> u, v, p, link;
vector<long long> minv;
vector<char> used;
vector<int> answer;       // номера выбранного в строке столбца
long long delta, cur;

int main() {
    freopen("assignment.in", "r", stdin);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf("%lld", &C[i][j]);
    fclose (stdin);

    u.assign(n + 1, 0), v.assign(n + 1, 0), p.assign(n + 1,0), link.assign(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        p[0] = i;
        int j0 = 0;
        minv.assign(n + 1, INF);
        used.assign(n + 1, false);

        //int cnt = 0;
do {
        //while (p[j0] != 0 || cnt < 1) {

            //cnt++;
            used[j0] = true;
            int i0 = p[j0], j1 = -1;
            delta = INF;
            for (int j = 1; j <= n; j++)
                if (!used[j]) {
                    if (C[i0][j] - u[i0] - v[j] < minv[j]) {
                        minv[j] = C[i0][j] - u[i0] - v[j];
                        link[j] = j0;
                    }
                    if (minv[j] < delta) {
                        delta = minv[j];
                        j1 = j;
                    }
                }
            for (int j = 0; j <= n; ++j)
                used[j] ? u[p[j]] += delta, v[j] -= delta : minv[j] -= delta;
            j0 = j1;
        } while (p[j0] != 0);


       // for(;j0;) {
        do{
            int j1 = link[j0];
            p[j0] = p[j1];
            j0 = j1;
        } while (j0);
    }

    freopen("assignment.out", "w", stdout);

    long long sum = 0l;
    answer.assign(n+1, 0);
    for (int j = 1; j <= n; ++j) {
        answer[p[j]] = j;
        sum += C[p[j]][j];
    }
    printf("%lld\n", sum);
    for (int j = 1; j <= n; ++j)
        printf("%d %d\n",p[j],j);
    fclose (stdout);

    return 0;
}
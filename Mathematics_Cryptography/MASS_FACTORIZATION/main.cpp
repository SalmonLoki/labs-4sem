#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
//4 60 14 3 55

using  namespace std;

unsigned long N = 1000000; // 2 <= a <= 10^6;


// возвращает дополнительный массив
vector<int> result (N + 1);
void createDOPsieveOfEratosthenes() {
    for (int i = 0; i < N+1; i++)
    result[i] = i;

    for (int i = 2; i * i <= N; i++)
        if (result[i] == i)
            for (int j = i*i; j <= N; j += i)
                result[j] = i;
}

int currNum;
vector<int> getMultipliers(int a){
    vector<int> multipliers;
    currNum = a;
    while (currNum != 1){
        multipliers.push_back( result[currNum] );
        currNum /= result[currNum];
    }

    sort(multipliers.rbegin(), multipliers.rend());
    return multipliers;
}

int main() {
    ios::sync_with_stdio(0);
    createDOPsieveOfEratosthenes();
    /*for (int j = 0; j < 10; j++)
        printf("%d ", result[j]);*/

    int n, a;
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        scanf("%d", &a);
        vector<int> answer = getMultipliers(a);

        if (answer.empty()) printf("%d ", a);
        else
        for (int j = answer.size()-1; j >= 0 ; j--)
            printf("%d ",answer[j]);
        printf("\n");
    }
    return 0;
}
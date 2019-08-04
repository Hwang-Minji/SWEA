/* 3233. 정삼각형 분할 놀이 */

#include <cstdio>
#include <iostream>
 
using namespace std;
 
int n, m;
 
int main() {
    int tc;
    scanf("%d", &tc);
 
    for (int T = 1; T <= tc; T++) {
        scanf("%d %d", &n, &m);
        long long div = n / m;
 
        printf("#%d %lld\n", T, div * div);
    }
 
    return 0;
}

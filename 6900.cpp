/* 6900번: 주혁이의 복권 당첨 */

#include <cstdio>
using namespace std;
 
#define ll long long
#define N 101
#define L 9
 
int n, m;
 
int main() {
    int tc;
    scanf("%d", &tc);
 
    for (int T = 1; T <= tc; T++) {
        ll sum = 0;
        char list[N][L] = { 0, };
        int pay[N] = { 0, };
 
        scanf("%d %d", &n, &m);
 
        for (int i = 0; i < n; i++) {
            scanf("%s", list[i]);
            scanf("%d", &pay[i]);
        }
 
        for (int i = 0; i < m; i++) {
            char str[N] = { 0, };
            scanf("%s", str);
 
            for (int j = 0; j < n; j++) {
                int cnt = 0;
 
                for (int k = 0; k < L; k++) {
                    if (list[j][k] != '*' && list[j][k] != str[k]) break;
                    cnt++;
                }
 
                if (cnt == L) {
                    sum += pay[j];
                    break;
                }
            }
        }
 
        printf("#%d %lld\n", T, sum);
    }
 
    return 0;
}

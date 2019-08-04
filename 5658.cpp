/* 5658. [모의 SW 역량테스트] 보물상자 비밀번호 */

#include <cstdio>
#include <string.h>
using namespace std;
 
#define ll long long
#define N 8
#define M 30
 
int n, m, k;
char arr[M];
char list[M][N];
 
ll hexToDec(int hex[]) {
    ll dec = 0;
    for (int i = 0; i < m - 1; i++) {
        dec += hex[i];
        dec *= 16;
    }
    dec += hex[m - 1];
    return dec;
}
 
int main() {
    int tc;
    scanf("%d", &tc);
 
    for (int T = 1; T <= tc; T++) {
        for (int i = 0; i < M; i++) 
            for (int j = 0; j < N; j++) list[i][j] = 0;
 
        scanf("%d %d", &n, &k);
        scanf("%s", arr);
        m = n / 4;
 
        for (int i = 0; i < n; i++) {
            char str[10] = { 0, };
            for (int j = 0; j < m; j++) {
                int k = (i + j) % n;
                str[j] = arr[k];
            }
 
            for (int j = 0; j < k; j++) {
                if (strcmp(str, list[j]) == 0) break;
                if (strcmp(str, list[j]) < 0) continue;
                else {
                    for (int l = k - 1; l > j; l--) strcpy(list[l], list[l - 1]);
                    strcpy(list[j], str);
                    break;
                }
            }
        }
 
        int hex[M] = { 0, };
        for (int i = 0; i < m; i++) {
            if (list[k - 1][i] >= '0' && list[k - 1][i] <= '9') hex[i] = list[k - 1][i] - '0';
            else hex[i] = list[k - 1][i] - 'A' + 10;
        }
        printf("#%d %lld\n", T, hexToDec(hex));
    }
     
    return 0;
}

/* 8104. 조 만들기 */

#include <cstdio>
#include <iostream>
 
using namespace std;
 
#define N 21
 
int n, k;
int arr1[N], arr2[N];
 
int main() {
    int tc;
    scanf("%d", &tc);
 
    for (int T = 1; T <= tc; T++) {
        scanf("%d %d", &n, &k);
         
        for (int i = 0; i < N; i++) {
            arr1[i] = 0;
            arr2[i] = 0;
        }
 
        int t = 1;
 
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                for (int j = 0; j < k; j++) {
                    arr1[j] += t;
                    t++;
                }
            } 
            else {
                for (int j = 0; j < k; j++) {
                    arr2[j] += t;
                    t++;
                }
            }
        }
 
        printf("#%d ", T);
        for (int i = 0; i < k; i++) {
            printf("%d ", arr1[i] + arr2[k - i - 1]);
        }
        printf("\n");
    }
 
    return 0;
}

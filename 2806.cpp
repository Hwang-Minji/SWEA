/* 2806번: N-Queen */

#include <cstdio>
using namespace std;
 
#define N 11
int map[N][N];
int n, ans = 0;
bool row[N], col[N];
 
int dr[2] = { -1, -1 };
int dc[2] = { 1, -1 };
 
bool run(int r, int c) {
    for (int i = 0; i < 2; i++) {
        int nr = r + dr[i], nc = c + dc[i];
 
        while (nr>=0 && nr<n && nc>=0 && nc<n) {
            if (map[nr][nc] == 1) return true;
            nr += dr[i], nc += dc[i];
        }
    }
    return false;
}
 
void dfs(int r, int c) {
    if (r == n) {
        ans++;
        return;
    }
     
    for (int i = 0; i < n; i++) {
        if (col[i]) continue;
        if (run(r, i)) continue;
 
        map[r][i] = 1, col[i] = true;
        dfs(r + 1, i);
        map[r][i] = 0, col[i] = false;
    }
}
 
int main() {
    int tc;
    scanf("%d", &tc);
 
    for (int T = 1; T <= tc; T++) {
        scanf("%d", &n);
        ans = 0;
 
        for (int i = 0; i < n; i++) {
            map[0][i] = 1, col[i] = true;
            dfs(1, i);
            map[0][i] = 0, col[i] = false;
        }
 
        printf("#%d %d\n", T, ans);
    }
 
    return 0;
}

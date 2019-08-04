/* 2819. 격자판의 숫자 이어 붙이기 */

#include <cstdio>
using namespace std;

int n = 4, l = 6, strCnt = 0;
int map[5][5];
bool check[10000000];
int dr[4] = { 0, 1, 0, -1 };
int dc[4] = { 1, 0, -1, 0 };

void dfs(int cnt, int r, int c, int sum) {
	if (cnt == 7) {
		if (!check[sum]) check[sum] = true, strCnt++;
		return;
	}

	for (int i = 0; i < 4; i++) {
		int nr = r + dr[i], nc = c + dc[i];
		if (nr >= 0 && nr < 4 && nc >= 0 && nc < 4) {
			dfs(cnt + 1, nr, nc, (sum * 10) + map[nr][nc]);
		}
	}
}

int main() {
	int tc;
	scanf("%d", &tc);

	for (int T = 1; T <= tc; T++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) 
				scanf("%d", &map[i][j]);
		}

		for (int i = 0; i < 10000000; i++) check[i] = false;
		strCnt = 0;
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) 
				dfs(1, i, j, map[i][j]);
		}
		
		printf("#%d %d\n", T, strCnt);
	}
	
	return 0;
}

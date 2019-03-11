/* 2117번: [모의 SW 역량테스트] 홈 방범 서비스 */


#include <cstdio>
using namespace std;

#define N 22

int n, m, k, cost, h, MAX;
int map[N][N] = { 0, };
bool flag;

int check(int r, int c) {
	int cnt = 0;

	for (int i = 0; i < k && c + i <= n; i++) {
		cnt += map[r][c + i];
		for (int j = 1; j < k - i && r - j >= 1; j++) cnt += map[r - j][c + i];
		for (int j = 1; j < k - i && r + j <= n; j++) cnt += map[r + j][c + i];
	}
	for (int i = 1; i < k && c - i >= 1; i++) {
		cnt += map[r][c - i];
		for (int j = 1; j < k - i && r - j >= 1; j++) cnt += map[r - j][c - i];
		for (int j = 1; j < k - i && r + j <= n; j++) cnt += map[r + j][c - i];
	}
	return cnt;
}

void run() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int cnt = check(i, j);
			if (cnt*m - cost >= 0 && cnt > MAX) MAX = cnt;
			if (cnt == h) {
				flag = true;
				return;
			}
		}
	}
}

int main() {
	int tc;
	scanf("%d", &tc);

	for (int T = 1; T <= tc; T++) {
		h = 0, MAX = 0, flag = false;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) map[i][j] = 0;
		}

		scanf("%d %d", &n, &m);
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				scanf("%d", &map[i][j]);
				if (map[i][j]) h++;
			}
		}

		for (int i = 1; i <= n+1; i++) {
			k = i;
			cost = k*k + (k - 1) * (k - 1);
			run();
			if (flag) break;
		}
		printf("#%d %d\n", T, MAX);
	}

	return 0;
}

/* 2112. [모의 SW 역량테스트] 보호 필름 */

#include <cstdio>
using namespace std;

#define D 15
#define W 22

int d, w, k, ans = 0;
int map[D][W];
bool flag = false;

bool check() {
	for (int i = 1; i <= w; i++) {
		int cnt = 1, cur = map[1][i];
		for (int j = 2; j <= d; j++) {
			if (cur == map[j][i]) cnt++;
			else cur = map[j][i], cnt = 1;
			if (cnt == k) break;
		}
		if (cnt != k) return false;
	}
	return true;
}

void dfs(int p, int cnt) {
	if (cnt == ans) {
		flag = check();
		return;
	}

	for (int i = p + 1; i <= d; i++) {
		int temp[W] = { 0, };
		for (int j = 1; j <= w; j++) temp[j] = map[i][j];

		for (int j = 0; j <= 1; j++) {
			for (int l = 1; l <= w; l++) map[i][l] = j;
			dfs(i, cnt + 1);
			if (flag) return;
		}
		for (int j = 1; j <= w; j++) map[i][j] = temp[j];
	}
}

int main() {
	int tc;
	scanf("%d", &tc);

	for (int T = 1; T <= tc; T++) {
		flag = false, ans = 0;
		scanf("%d %d %d", &d, &w, &k);

		for (int i = 1; i <= d; i++) {
			for (int j = 1; j <= w; j++) 
				scanf("%d", &map[i][j]);
		}

		if (check()) {
			printf("#%d %d\n", T, ans);
			continue;
		}

		while (1) {
			ans++;
			dfs(0, 0);
			if (flag) break;
		}
		printf("#%d %d\n", T, ans);
	}

	return 0;
}

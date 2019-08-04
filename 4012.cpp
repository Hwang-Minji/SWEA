/* 4012. [모의 SW 역량테스트] 요리사 */

#include <cstdio>
using namespace std;

#define N 17
#define INF 2e9

int n, MIN = INF;
int map[N][N];
int d[N][N];
bool vst[N];

void dfs(int cnt, int k) {
	if (cnt == n / 2) {
		int a = 0, b = 0;
		for (int i = 1; i <= n; i++) {
			if (vst[i]) {
				for (int j = i + 1; j <= n; j++) if (vst[j]) a += d[i][j];
			}
			else {
				for (int j = i + 1; j <= n; j++) if (!vst[j]) b += d[i][j];
			}
		}
        
        int dif = a - b;
		if(dif < 0) dif *= -1;
		MIN = dif < MIN ? dif : MIN;

		return;
	}

	for (int i = k + 1; i <= n; i++) {
		vst[i] = true;
		dfs(cnt + 1, i);
		vst[i] = false;
	}
}

int main() {
	int tc;
	scanf("%d", &tc);

	for (int T = 1; T <= tc; T++) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) 
				scanf("%d", &map[i][j]);
		}

		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) 
				d[i][j] = map[i][j] + map[j][i];
		}

		MIN = INF;
		for (int i = 1; i <= n / 2; i++) {
			vst[i] = true;
			dfs(1, i);
			vst[i] = false;
		}

		printf("#%d %d\n", T, MIN);
	}

	return 0;
}

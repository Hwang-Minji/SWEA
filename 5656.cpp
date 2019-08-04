/* 5656. [모의 SW 역량테스트] 벽돌 깨기 */

#include <cstdio>
#include <vector>
using namespace std;

#define pi pair<int, int>
#define N 16
#define M 13

int map[N][M];
int check[M];

int n, m, k;
int total = 0, MAX;
int runSum = 0;

int dr[4] = { 0, 1, 0, -1 };
int dc[4] = { 1, 0, -1, 0 };

void run(int r, int c, int cnt) {
	for (int i = 0; i < 4; i++) {
		int nr = r, nc = c;

		for (int j = 1; j <= cnt; j++) {
			nr += dr[i], nc += dc[i];
			if (nr < 0 || nr >= n || nc < 0 || nc >= m) break;
			if (i == 3 && nr < check[nc]) break;
			
			if (map[nr][nc] == 0) continue;
			runSum++;
			int tempCnt = map[nr][nc];
			map[nr][nc] = 0;

			if (tempCnt >= 1) {
				run(nr, nc, tempCnt - 1);
			}
		}
	}
}

void clean() {
	for (int i = 0; i < m; i++) {
		vector<int> temp;
		for (int j = n - 1; j >= 0; j--) {
			if (map[j][i] != 0) {
				temp.push_back(map[j][i]);
				map[j][i] = 0;
			}
		}

		check[i] = n - temp.size();
		if (temp.size() == 0) check[i] = -1;

		for (int j = 0; j < temp.size(); j++) {
			map[n - 1 - j][i] = temp[j];
		}
	}
}

void dfs(int cnt, int sum) {
	if (sum == total) {
		MAX = sum;
		return;
	}
	if (cnt == k) {
		if (sum > MAX) MAX = sum;
		return;
	}

	for (int i = 0; i < m; i++) {
		if (check[i] == -1) continue;

		int tempMap[N][M] = { 0, };
		for (int j = 0; j < n; j++) {
			for (int l = 0; l < m; l++) {
				tempMap[j][l] = map[j][l];
			}
		}

		int tempCheck[M] = { 0, };
		for (int j = 0; j < m; j++) {
			tempCheck[j] = check[j];
		}

		runSum = 1;
		int cntTemp = map[check[i]][i];
		map[check[i]][i] = 0;
		run(check[i], i, cntTemp - 1);
		clean();

		dfs(cnt + 1, sum + runSum);

		for (int j = 0; j < n; j++) {
			for (int l = 0; l < m; l++) {
				map[j][l] = tempMap[j][l];
			}
		}
		for (int j = 0; j < m; j++) {
			check[j] = tempCheck[j];
		}

		if (MAX == total) return;
	}
}

int main() {
	int tc;
	scanf("%d", &tc);

	for (int T = 1; T <= tc; T++) {
		scanf("%d %d %d", &k, &m, &n);
		total = 0, MAX = 0;
		for (int i = 0; i < m; i++) check[i] = -1;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				scanf("%d", &map[i][j]);

				if (map[i][j] > 0) {
					total++; 
					if(check[j] == -1) check[j] = i;
				}
			}
		}
		
		dfs(0, 0);
		printf("#%d %d\n", T, total - MAX);
	}
	return 0;
}

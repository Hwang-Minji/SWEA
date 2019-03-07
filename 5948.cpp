/* 5948번: 새샘이의 7-3-5 게임 */

#include <cstdio>
using namespace std;

int num[7];
bool check[301] = { false, };

void dfs(int k, int cnt, int sum) {
	if (cnt == 3) {
		check[sum] = true;
		return;
	}
	for (int i = k + 1; i < 7; i++) 
		dfs(i, cnt + 1, sum + num[i]);
}

int main() {
	int tc;
	scanf("%d", &tc);

	for (int T = 1; T <= tc; T++) {
		for (int i = 0; i <= 300; i++) check[i] = false;
		for (int i = 0; i < 7; i++) scanf("%d", &num[i]);
		
		for (int i = 0; i <= 4; i++) dfs(i, 1, num[i]);
		int cnt = 0;
		for (int i = 300; i >= 0; i--) {
			if (check[i]) cnt++;
			if (cnt == 5) {
				printf("#%d %d\n", T, i);
				break;
			}
		}
	}
	return 0;
}

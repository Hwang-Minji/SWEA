/* 7087번: 문제 제목 붙이기 */

#include <cstdio>
using namespace std;

int main() {
	int tc;
	scanf("%d", &tc);

	for (int T = 1; T <= tc; T++) {
		bool vst[27] = { false, };
		int n;
		scanf("%d", &n);

		for (int i = 0; i < n; i++) {
			char str[100];
			scanf("%s", str);
			vst[str[0] - 'A'] = true;
		}

		int cnt = 0;
		for (int i = 0; i < n; i++) {
			if (!vst[i]) break;
			cnt++;
		}
		printf("#%d %d\n", T, cnt);
	}

	return 0;
}

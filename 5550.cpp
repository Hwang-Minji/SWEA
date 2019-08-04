/* 5550. 나는 개구리로소이다 */

#include <cstdio>
#include <string.h>
using namespace std;

int n;
char croak[6] = { 'c', 'r', 'o', 'a', 'k', 0 };

int run(char str[]) {
	int cnt = 0;
	int maxIdx = 0;
	int nextChar[2502] = { 0, };
	bool flag = false;

	if (n % 5 != 0) cnt = -1;

	while (!flag && cnt == 0) {
		for (int i = 0; i < n; i++) {
			if (str[i] != '.') {
				for (int j = 0; j < 2500; j++) {
					if (croak[nextChar[j]] == str[i]) {
						if (str[i] == 'k' && j >= cnt) cnt++;
						nextChar[j] = (nextChar[j] + 1) % 5;
						maxIdx = maxIdx > j ? maxIdx : j;
						str[i] = '.';
						break;
					}
				}
				if (str[i] != '.') {
					flag = true;
					break;
				}
			}
		}
		if (maxIdx >= cnt) flag = true;
	}
	if (flag) cnt = -1;

	return cnt;
}

int main() {
	int tc;
	scanf("%d", &tc);

	for (int T = 1; T <= tc; T++) {
		char str[2505] = { 0, };
		scanf("%s", str);
		n = strlen(str);
		printf("#%d %d\n", T, run(str));
	}

	return 0;
}

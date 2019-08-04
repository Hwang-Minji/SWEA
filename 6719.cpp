/* 6719. 성수의 프로그래밍 강좌 신청 */

#include <cstdio>
#include <algorithm>
#include <functional>
using namespace std;

int arr[10004];
int n, k;

int main() {
	int tc;
	scanf("%d", &tc);
	
	for (int T = 1; T <= tc; T++) {
		scanf("%d %d", &n, &k);

		for (int i = 0; i < n; i++) 
			scanf("%d", &arr[i]);

		sort(arr, arr + n, greater<int>());
		float ans = 0;

		for (int i = k - 1; i >= 0; i--) 
			ans = (ans + arr[i]) / 2;

		printf("#%d %.6f\n", T, ans);
	}

	return 0;
}

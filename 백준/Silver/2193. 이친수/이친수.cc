// 2193
// 
// 이친수 조건
// 1. 첫번째 시작수가 1
// 2. 11을 부분집합 x
//
// input 1 <= N <= 90
// 
// - 아이디어
// 2차원 dp로 접근
// 마지막 숫자가 1 -> 0만 가능
// "			0 -> 0,1 가능
// 점화식 dp[n][마지막숫자] = dp[n-1][가능한숫자조합]
// ex) dp[n][1] = dp[n-1][0] (only)
//
// - 복잡도
// O(n) ok
// 
// - 자료구조
// int64[][] : dp
//

#include <bits/stdc++.h>

int64_t dp[91][2];

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;

	// init
	dp[1][0] = 0;
	dp[1][1] = 1;

	// solve
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= 1; j++) {
			if (j == 0) {
				dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
			}
			else if (j == 1) {
				dp[i][1] = dp[i - 1][0];
			}
			//std::cout << i << "," << j << "=" << dp[i][j] <<"\n";
		}
	}

	// answer
	std::cout << dp[n][0] + dp[n][1];

	return 0;
}
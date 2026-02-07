// 11057
// 
// - 아이디어
// 점화식 -> dp[n][마지막숫자] = dp[n-1][가능한숫자 전부]
// ex) dp[n][9] = dp[n-1][9] ... dp[n-1][0];
// ex) dp[n][8] = dp[n-1][8] ... dp[n-1][0];
// 
// - 복잡도
// O(n)? <- 가능
// n*10^2 => 약 10^5
// 
// - 자료구조
// int[][] : dp

#include <bits/stdc++.h>

constexpr int MODULER = 10'007;
int dp[1001][10];

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int N;
	std::cin >> N;

	// init
	for (int i = 0; i <= 9; i++) {
		dp[1][i] = 1;
	}

	// solve
	for (int n = 2; n <= N; n++) {
		for (int m = 0; m <= 9; m++) {
			for (int i = 0; i <= m; i++) {
				dp[n][m] = (dp[n][m] + dp[n - 1][i]) % MODULER;
			}
		}
	}

	// answer
	int answer = 0;
	for (int i = 0; i <= 9; i++) {
		answer = (answer + dp[N][i]) % MODULER;
	}
	std::cout << answer;

	return 0;
}
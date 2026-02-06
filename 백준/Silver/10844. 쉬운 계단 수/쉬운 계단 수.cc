// 10844
// 
// - 아이디어
// 계단수? -> n개일때 dp[n-1] + ?
// ? -> 앞의 모든 경우의 수에 따른 경우의 수는 18개 dp[n] = dp[n-1] + 18
// ----------- 라고 생각했으나
// 
// dp[n] = dp[n-1] * ? 이 되어야한다.
// 앞의 경우의 수 * 가짓수이기 때문에 중간수(1~8)까지는 *2가 그대로 적용된다 하지만 양극단값 0,9는 가짓수가 존재하지 않음 
// 하나의 가지만 존재하기 때문에 카운트하지 않는다. 그래서 *2 - 2 점화식을 도출하였다.
// 
// ----------- 도 아니고
// 
// 거꾸로 가야한다.
// dp[n][마지막숫자] = dp[n-1][가능한숫자]
// 마지막숫자가 9라면 n-1개일때의 마지막숫자는 8이여야한다! 
// ex) dp[n][9] = dp[n-1][8]
// ex) dp[n][8] = dp[n-1][7] + dp[n-1][9] (1~8이 해당)
// ex) dp[n][0] = dp[n-1][1]
// 
// bottomup
// 출력은 int64 ^
// 
// - 복잡도
// 2차원 완탐 -> 10^3 => 10*n => O(n)
// - 자료구조
// int64_t[][] : dp

#include <bits/stdc++.h>
#define MODULER 1'000'000'000
int64_t dp[101][10] = {};

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int N;
	std::cin >> N;
	
	// Init
	for (int i = 1; i <= 9; i++) dp[1][i] = 1;

	// Solve
	for (int n = 2; n <= N; n++) {
		for (int m = 0; m <= 9; m++) {
			if		(m == 0) dp[n][0] = dp[n - 1][1];
			else if (m == 9) dp[n][9] = dp[n - 1][8];
			else			 dp[n][m] = dp[n - 1][m - 1] + dp[n - 1][m + 1];
			dp[n][m] = dp[n][m] % MODULER;
		}
	}

	// Result
	int64_t answer = 0;
	for (int i = 0; i <= 9; i++) {
		answer += dp[N][i];
	}
	std::cout << answer % MODULER;
	return 0;
}
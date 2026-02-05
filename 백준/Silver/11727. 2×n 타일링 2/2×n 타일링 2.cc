// 11727
// 
// dp : 문제를 작은 문제로 나누어 해결
// 점화식 : dp[n] = dp[n-1] + dp[n-2] + dp[n-2]
// 
// - 복잡도
// 메모이제이션을 적용한 O(n)
// 
// - 자료구조
// 배열 int[]
#include <bits/stdc++.h>

std::vector<int> dp(1001);

int D(int n)
{
	if (dp[n] != 0) {
		return dp[n];
	}
	return dp[n] = (D(n - 1) + 2 * D(n - 2)) % 10'007;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int N;
	dp[1] = 1;
	dp[2] = 3;
	std::cin >> N;
	std::cout << D(N);
	//dp[N] = dp[N - 1] + 2 * dp[N - 2];

	return 0;
}
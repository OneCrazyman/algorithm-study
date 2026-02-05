// 1463
// bottom up
// dp 오름차순 정복 방법으로 접근
// 1 ~ n까지 작성, 2나 3으로 나누고 dp에서 최적값이 있으면 해당 기반으로 dp를 업데이트하자

#include <bits/stdc++.h>

std::vector<int> dp(1'000'001);
int N;

void CalculateDp(int);

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin >> N;
	
	dp[1] = 0;

	for (int i = 2; i <= N; i++) {
		CalculateDp(i);
	}

	std::cout << dp[N];
	return 0;
}

void CalculateDp(int num)
{
	dp[num] = dp[num - 1] + 1;
	if (num % 2 == 0) {
		dp[num] = std::min(dp[num], dp[num / 2] + 1);
	}
	if (num % 3 == 0) {
		dp[num] = std::min(dp[num], dp[num / 3] + 1);
	}
}

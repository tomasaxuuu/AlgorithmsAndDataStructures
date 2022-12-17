#include <iostream>
using namespace std;
int main()
{
	int n, k;
	cin >> n >> k;
	int dp[20][2];
	dp[1][0] = 0;
	dp[1][1] = k - 1;
	for (int len = 2; len <= n; ++len) {
		dp[len][0] = dp[len - 1][1];
		dp[len][1] = (dp[len - 1][0] + dp[len - 1][1]) * (k - 1);
	}
	cout << dp[n][0] + dp[n][1] << endl;
	return 0;
}

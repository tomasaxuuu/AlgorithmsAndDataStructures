#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int n = 0;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}
	vector<int> dp(n), left(n);
	dp[0] = v[0];
	left[0] = 0;
	for (int i = 1; i < n; ++i) {
		if (dp[i - 1] >= 0) {
			dp[i] = dp[i - 1] + v[i];
			left[i] = left[i - 1];
		}
		else {
			dp[i] = v[i];
			left[i] = i;
		}
	}
	int right = max_element(dp.begin(), dp.end()) - dp.begin();
	cout << left[right] << ' ' << right;
	return 0;
}

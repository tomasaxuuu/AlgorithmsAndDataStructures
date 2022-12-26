#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int main()
{
    const int SIZE = 100100;

    int len[SIZE];

    vector<int> dp;

    int n, a1, k, b, m;
    cin >> n >> a1 >> k >> b >> m;
    vector<int> arr(n);
    arr[0] = a1;

    for (int i = 1; i < n; ++i)
    {
        arr[i] = (k * arr[i - 1] + b) % m;
    }

    dp.push_back(arr[0]);

    len[0] = 1;

    for (int i = 1; i < n; ++i)
    {
        if (arr[i] > dp.back())
        {
            dp.push_back(arr[i]);
            len[i] = dp.size();
        }
        else
        {
            int indexElement = lower_bound(dp.begin(), dp.end(), arr[i]) - dp.begin();
            len[i] = indexElement + 1;
            dp[indexElement] = arr[i];
        }
    }

    int i = max_element(len, len + n) - len;
	stack <int> stack;
	stack.push(arr[i]);
	for (int j = i - 1; j >= 0; --j) {
		if (arr[j] < arr[i] && len[j] == len[i] - 1) {
			i = j;
			stack.push(arr[i]);
		}
	}
	while (!stack.empty()) {
		cout << stack.top() << ' ';
		stack.pop();
	}

	return 0;
}
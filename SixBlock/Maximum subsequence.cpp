#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> values(n);
	vector<int> counters(n);
	for (int i = 0; i < n; ++i) {
		cin >> values[i];
	}
	int max_counter = 0;
	for (int i = 0; i < n; ++i) {
		counters[i] = 0;
		for (int j = i - 1; j >= 0; --j) {
			if (values[j] < values[i])
				counters[i] = max(counters[j], counters[i]);
		}
		counters[i]++;
		max_counter = max(max_counter, counters[i]);
	}
	cout << max_counter;
	return 0;
}

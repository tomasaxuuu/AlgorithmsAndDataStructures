#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, max = -1001, indexMax = 0, l, r;
	cin >> n;
	vector <int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cin >> l >> r;
	for (int i = l - 1; i < r; i++) {
		if (arr[i] > max) {
			max = arr[i];
			indexMax = i;
		}
	}
	cout << max << " " << indexMax + 1;
	return 0;
}
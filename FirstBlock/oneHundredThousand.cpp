#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int binary(int i) {
	int count = 0;
	while (i >= 1) {
		count += i % 2;
		i /= 2;
	}
	return count;
}


bool cmpBinary(int a, int b) {
	if (binary(a) == binary(b)) {
		return a < b;
	}
	return binary(a) > binary(b);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	vector <int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());
	for (int i = 0; i < n; i++) {
		cout << arr[i] << ' ';
	}
	cout << endl;
	sort(arr.begin(), arr.end(), cmpBinary);
	for (int i = 0; i < n; i++) {
		cout << arr[i] << ' ';
	}
	return 0;
}
#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int x;
	cin >> x;
	int number = arr[0];
	for (int i = 0; i < n; i++) {
		if (abs(arr[i] - x) < abs(number - x) || abs(arr[i] - x) == abs(number - x) && arr[i] < number) {
			number = arr[i];
		}
	}
	cout << number;
	return 0;
}
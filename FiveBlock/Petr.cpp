#include <iostream>
using namespace std;
int n, a[16];
int main()
{
	bool k = false;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < (1 << n); i++) {
		int c = 0;
		for (int j = 0; j < n; j++) {
			if (i & (1 << j)) {
				c += a[j];
			}
			else {
				c -= a[j];
			}
		}
		if (c % 360 == 0) {
			k = true;
		}
	}
	if (k) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}
	return 0;
}

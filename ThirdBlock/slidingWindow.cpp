#include <iostream>
#include <deque>
#include <vector>

using namespace std;

void sliding_window(int n, const vector<int>& v, int k) {
	deque<pair<int, int> > dq;
	dq.push_back({ v[0], 0 });
	for (int i = 1; i < k - 1; ++i) {
		while (dq.size() && dq.back().first >= v[i]) {
			dq.pop_back();
		}
		dq.push_back({ v[i], i });
	}
	for (int i = k - 1; i < v.size(); ++i) {
		if (dq.front().second < i - k + 1) {
			dq.pop_front();
		}
		while (dq.size() && dq.back().first >= v[i]) {
			dq.pop_back();
		}
		dq.push_back({ v[i], i });
		cout << dq.front().first << endl;
	}
	cout << endl;
}

int main() {
	int n = 0, k = 0;
	cin >> n >> k;
	vector <int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sliding_window(n, a, k);
	return 0;
}
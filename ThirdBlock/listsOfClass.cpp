#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int main() {
	pair<int, string> p;
	vector <pair<int, string>> v;
	int c = 0;
	string n = "";
	queue<string> arr[3];

	while (cin >> c >>  n) {
		p.first = c;
		p.second = n;
		v.push_back(p);
	}

	for (int i = 0; i < v.size(); i++) {
		arr[v[i].first - 9].push(v[i].second);
	}

	for (int i = 0; i < 3; i++) {
		queue<string> a = arr[i];
		while (!a.empty()) {
			string s = a.front();
			a.pop();
			cout << i + 9 << ' ' << s << endl;
		}
	}
	return 0;
}
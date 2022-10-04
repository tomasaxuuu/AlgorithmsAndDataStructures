#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
using namespace std;

class Comparator {
private:
	string nickName = "";
	double points = 0;
public:
	void inputVector() {
		cin >> points >> nickName;
	}
	void outputVector() {
		cout << fixed << setprecision(2) << points << ' ' << nickName << endl;
	}
	bool operator < (Comparator arr) {
		return points > arr.points;
	}
};


int main() {
	int n, m;
	vector <Comparator> arr;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> m;
		for (int j = 0; j < m; j++) {
			Comparator c;
			c.inputVector();
			arr.push_back(c);
		}
	}
	sort(arr.begin(), arr.end());
	cout << arr.size() << endl;
	for (int i = 0; i < arr.size(); i++) {
		arr[i].outputVector();
	}
	return 0;
}
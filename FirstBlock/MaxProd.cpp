#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	ios_base::sync_with_stdio(false);
	FILE* f1;
	fopen_s(&f1, "D:\\input.txt", "rt");
	fscanf(f1, "%d", &n);
	vector <int> a(n);
	long long prod, first, second;
	for (int i = 0; i < n; i++) {
		fscanf(f1, "%d", &a[i]);
	}
	sort(a.begin(), a.end());
	first = a[n - 3] * a[n - 2] * a[n - 1];
	second = a[n - 1] * a[0] * a[1];
	if (first > second) {
		prod = first;
	}
	else {
		prod = second;
	}
	cout << prod;
	return 0;
}
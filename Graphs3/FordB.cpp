#include<iostream>
#define INF 30000
using namespace std;
int main() {
	int n, m, i, j, k; bool f;
	cin >> n;
	int d[n + 1]; d[1] = 0;
	for (i = 2; i <= n; ++i)d[i] = INF;
	do {
		f = false;
		for (i = 1; i < n; ++i)
			for (j = i + 1; j <= n; ++j) {
				k = (179 * i + 719 * j) % 1000 - 500;
				if (d[i]<INF && d[j]>d[i] + k)
				{
					f = true; d[j] = d[i] + k;
				}
			}
	} while (f);
	cout << d[n];
	return 0;
}
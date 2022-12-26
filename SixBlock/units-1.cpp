#include <iostream>
using namespace std;
int main()
{
    int n, res[5000];
    cin >> n;
    res[0] = 1;
    for (int i = 1; i <= n; i++) {
        res[i] = i;
        for (int j = 1; 2 * j < i; j++) {
            if (res[j] + res[i - j] < res[i]) {
                res[i] = res[j] + res[i - j];
            }
        }
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                if (res[j] + res[i / j] < res[i]) res[i] = res[j] + res[i / j];
            }
        }
    }
    cout << res[n];
}
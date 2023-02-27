﻿#include <iostream>
using namespace std;
long long arr[101][101];
int main()
{
    long long n, x = 0, y = 0, z = 0, s = -1;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> arr[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            for (int k = j + 1; k <= n; k++) {
                if (s == -1) {
                    s = arr[i][j] + arr[i][k] + arr[k][j];
                    x = i;
                    y = j;
                    z = k;
                }
                else if (s > arr[i][j] + arr[i][k] + arr[k][j]) {
                    s = arr[i][j] + arr[i][k] + arr[k][j];
                    x = i;
                    y = j;
                    z = k;
                }
            }
        }
    }
    cout << x << " " << y << " " << z;
    return 0;
}
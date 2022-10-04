#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
int main() {
    int n, m;
    cin >> n;
    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cin >> m;
    int* x = new int[m];
    for (int i = 0; i < m; i++) {
        cin >> x[i];
    }
    int sum = 0;
    int* p;
    int i = 0;
    reverse(arr, arr + n);
    while (i != m) {
        p = find(arr, arr + n, x[i]);
        if (p != arr + n) {
            sum += n - distance(arr, p) - 1;
        }
        else {
            sum--;
        }
        i++;
    }
    cout << sum;
    return 0;
}
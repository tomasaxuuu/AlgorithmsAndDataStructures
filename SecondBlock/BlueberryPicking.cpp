#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int* arr = new int[n + 2];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    arr[n] = arr[0];
    arr[n + 1] = arr[1];
    int max = 0;
    for (int i = 1; i < n + 1; i++) {
        int sum = arr[i - 1] + arr[i] + arr[i + 1];
        if (sum > max) {
            max = sum;
        }
    }
    cout << max;
    return 0;
}
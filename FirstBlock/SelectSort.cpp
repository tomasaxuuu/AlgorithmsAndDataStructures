#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n, k;
    cin >> n;
    vector <int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cin >> k;
    k += 1;
    int count = 0;
    for (int i = 0; i < n - 1; i++) {
        int pos = i;
        count++;
        if (count == k) {
            break;
        }
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[pos]) {
                pos = j;
            }

        }
        swap(arr[i], arr[pos]);
    }
    for (int i = 0; i < n; i++) {
        cout << arr[i] << ' ';
    }
    return 0;
}
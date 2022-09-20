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
    for (int i = 0; i < n; i++) {
        count++;
        if (count == k) {
            break;
        }
        int j = i + 1;
        while (j && arr[j - 1] > arr[j]) {
            swap(arr[j - 1], arr[j]);
            j--;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << arr[i] << ' ';
    }
    return 0;
}
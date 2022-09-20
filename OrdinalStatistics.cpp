#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void printArray(unsigned long long* array, int n)
{
    for (int i = 0; i < n; ++i)
        cout << array[i] << " ";
    cout << endl;
}
void quickSort(unsigned long long* array, int low, int high)
{
    int i = low;
    int j = high;
    int pivot = array[(i + j) / 2];
    int temp;

    while (i <= j)
    {
        while (array[i] < pivot) {
            i++;
        }
        while (array[j] > pivot) {
            j--;
        }
        if (i <= j)
        {
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            i++;
            j--;
        }
    }
    if (j > low) {
        quickSort(array, low, j);
    }
    if (i < high) {
        quickSort(array, i, high);
    }
}

int main()
{
    int n, x, k;
    unsigned long long y;
    cin >> n;
    unsigned long long arr[100000];
    cin >> arr[0] >> x >> y;
    cin >> k;
    unsigned long long mod = (pow(10, 9) + 7);
    for (int i = 1; i < n; i++) {
        arr[i] = (arr[i - 1] * x + y) % mod;
    }
    printArray(arr, n);
    quickSort(arr, 0, n);
    printArray(arr, n);
    cout << arr[k];
    return (0);
}
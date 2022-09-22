#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <time.h>
#include <random>
#include <algorithm>
#define endl '\n'
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
int arr[(int)4e7 + 10], k, n;

int m_rand(int l, int r) {
    return 1.0 * rand() / RAND_MAX * (r - l) + l;
}

void quick_sort(int* ar, int left, int right) {
    if (left >= right) {
        return;
    }
    int x = m_rand(left, right);
    swap(ar[left], ar[x]);
    x = ar[left];
    int li = left + 1, ri = right;
    while (true) {
        while (ar[li] < x && li < right) {
            ++li;
        }
        while (ar[ri] > x && ri > left) {
            --ri;
        }
        if (li >= ri) {
            break;
        }
        swap(ar[li], ar[ri]);
        ++li;
        --ri;
    }
    swap(ar[left], ar[ri]);
    if (k < ri) {
        quick_sort(ar, left, ri - 1);
    } else if(k > ri) {
        quick_sort(ar, ri + 1, right);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    long long x, y;
    cin >> n;
    int* arr = new int[n];
    cin >> arr[0] >> x >> y;
    for (int i = 1; i < n; i++) {
        arr[i] = (arr[static_cast<long long>(i) - 1] * x + y) % MOD;
    }
    cin >> k;
    quick_sort(arr, 0, n - 1);
    cout << arr[k];
    return 0;
}
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector <int> platf(n);
    for (int i = 0; i < n; i++)
    {
        cin >> platf[i];
    }
    vector <int> arr;
    arr.push_back(0);
    arr.push_back(abs(platf[1] - platf[0]));
    for (int i = 2; i < n; i++)
    {
        arr.push_back((min(abs(platf[i] - platf[i - 1]) + arr[i - 1], 3 * abs(platf[i] - platf[i - 2]) + arr[i - 2])));
    }
    cout << arr[n - 1];
    return 0;
}
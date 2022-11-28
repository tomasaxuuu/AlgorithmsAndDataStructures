#include <iostream>
using namespace std;

int n, k;
bool used[10];

void rec(int n1, int k1) {
    if (k1 == k) {
        for (int i = 0; i < n + 1; ++i) {
            if (used[i]) {
                cout << i << ' ';
            }
        }
        cout << endl;
        return;
    }
    if (n1 + 1 >= n) {
        return;
    }
    used[n1 + 1] = true;
    rec(n1 + 1, k1 + 1);
    used[n1 + 1] = false;
    rec(n1 + 1, k1);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    rec(0, 0);

    return 0;
}
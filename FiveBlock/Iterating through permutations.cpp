#include <iostream>
using namespace std;

int n;
bool used[10];
int ar[10];

void rec(int i) {
    if (i == n) {
        for (int i = 0; i < n; ++i)
            cout << ar[i] << ' ';
        cout << endl;
        return;
    }
    for (int j = 1; j < n + 1; ++j) {
        if (!used[j]) {
            used[j] = true;
            ar[i] = j;
            rec(i + 1);
            used[j] = false;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    rec(0);
    
	return 0;
}

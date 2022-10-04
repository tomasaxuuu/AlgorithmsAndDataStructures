#include <iostream>
#include <cmath>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    int x, y;
    cin >> n >> x >> y;
    int time = 0;
    int nx = n * y / (x + y);
    time = min((n - nx) * y, (nx + 1) * x);
    cout << time;
    return 0;
}

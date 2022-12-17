#include <iostream>
#include <string>
using namespace std;
string a, b;
bool used[1010][1010];
int dp[1010][1010];
int rec(int n, int m) {
    if (min(n, m) == 0)
        return 0;
    if (used[n][m])
        return dp[n][m];
    used[n][m] = 1;
    if (a[n - 1] == b[m - 1])
        return dp[n][m] = rec(n - 1, m - 1) + 1;
    return dp[n][m] = max(rec(n - 1, m), rec(n, m - 1));
}
int main()
{
    cin >> a >> b;
    cout << rec(a.length(), b.length());
    return 0;
}
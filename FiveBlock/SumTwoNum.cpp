#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    string perX = to_string(a);
    string perY = to_string(b);
    string perZ = "";
    sort(begin(perX), end(perX));
    sort(begin(perY), end(perY));
    do
    {
        a = stoi(perX);
        if (a > c) break;
        perZ = to_string(c - a);
        while (perZ.size() < perY.size()) {
            perZ += '0';
        }
        sort(begin(perZ), end(perZ));
        if (perZ == perY)
        {
            cout << "YES\n" << a << " " << c - a << endl;
            return 0;
        }
    } while (next_permutation(begin(perX), end(perX)));
    cout << "NO\n";
}

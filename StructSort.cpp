#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct man {
    string lastname;
    int f, s, l;
};

bool cmp(man a, man b) {
    if (a.f + a.s + a.l == b.f + b.s + b.l) {
        return a.lastname < b.lastname;
    }
    return a.f + a.s + a.l > b.f + b.s + b.l;
}

int main() {
    int n;
    cin >> n;
    vector <man> a(n);
    for (int i = 0; i < n; i++) {
        int tempF, tempS, tempL;
        string tempLast;
        cin >> tempLast >> tempF >> tempS >> tempL;
        man struct_temp;
        struct_temp.lastname = tempLast;
        struct_temp.f = tempF;
        struct_temp.s = tempS;
        struct_temp.l = tempL;
        a[i] = struct_temp;
    }
    sort(a.begin(), a.end(), cmp);
    for (auto now : a) {
        cout << now.lastname << " " << now.f + now.s + now.l << endl;
    }
    return 0;
}
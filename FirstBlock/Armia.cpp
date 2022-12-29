#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt"); out.clear();
    struct Set {
        const int p = 100;
        vector <int> s;
        vector <int> a;
        Set(const int n)
            : a(n, 0)
            , s((n + p - 1) / p, 0)
        {}
        void add(const int i) {
            a[i]++;
            s[i / p]++;
        }
        int countUp(const int index) const {
            int pe = (index + p - 1) / p * p;
            int sum = 0;
            for (int i = index; i < (int)a.size() && i < pe; i++) {
                sum += a[i];
            }

            for (int i = pe / p; i < (int)s.size(); i++) {
                sum += s[i];
            }
            return sum;
        }
    };

    int n, m = 0, k;
    in >> n >> k;
    for (int z = 1; z <= k; z++) {
        Set set(n);  
        for (int i = 0; i < n; i++) {
            int rost;
            in >> rost;
            rost--;
            m += set.countUp(rost + 1); 
            set.add(rost); 
        }
    }
    out << m;
    return 0;
}
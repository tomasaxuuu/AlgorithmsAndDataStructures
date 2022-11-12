#include <iomanip>
#include <iostream>
#include <set>

using namespace std;
int main() {

    multiset<long> numbers;
    long n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        long number;
        cin >> number;
        numbers.insert(number);
    }

    double sum = 0;
    while (numbers.size() > 1) {
        auto get = [&]() {
            int r = *numbers.begin();
            numbers.erase(numbers.begin());
            return r;
        };
        int a = get();
        int b = get();
        sum += a + b;
        numbers.insert(a + b);
    }
    cout << setprecision(2) << fixed << sum * 0.05;
}
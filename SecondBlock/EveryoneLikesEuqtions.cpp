#include <iostream>
#include <iomanip>
using namespace std;
const double EPS = 1e-9;
const double e = 2.718281828459045;

double exponent(double x) {
	return exp(x) + log(x);
}

double cube_square(double y) {
	double left = 0, right = max(1., y);
	while (left + EPS < right) {
		double mid = (left + right) / 2;
		if (exponent(mid) > y)
			right = mid;
		else
			left = mid;
	}
	return (left + right) / 2;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	srand(time(0));
    double A;
    cin >> A;
    cout << fixed << setprecision(6) << cube_square(A);
    return 0;
}
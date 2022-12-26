#include <fstream>
#include <vector>
#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<vector<int>> field(n, vector <int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char c;
            cin >> c;
            field[i][j] = (c == '1');
        }
    }
    int field_max = field[0][0];
    for (int i = 0; i < n; i++) {
        if (true == field[i][n - 1] || true == field[n - 1][i]) {
            field_max = 1;
            break;
        }
    }
    for (int i = n - 2; i >= 0; --i) {
        for (int j = n - 2; j >= 0; --j) {
            if (field[i][j]) {
                field[i][j] = min(field[i + 1][j], field[i][j + 1]);
                field[i][j] = min(field[i][j], field[i + 1][j + 1]);
                field[i][j]++;
            }
            field_max = max(field[i][j], field_max);
        }
    }
    cout << field_max * field_max;
    return 0;
}
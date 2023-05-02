#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

const int INF = 1000000000; // константа для бесконечности
const int MAXN = 100; // максимальное количество городов

int n, k; // количество городов и количество дорог
int d[MAXN + 1][MAXN + 1]; // матрица смежности графа

int main() {
    cin >> n >> k; // считываем количество городов и дорог

    // Инициализируем матрицу смежности
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) {
                d[i][j] = 0;
            }
            else {
                d[i][j] = INF;
            }
        }
    }

    // Считываем информацию о дорогах
    for (int i = 0; i < k; i++) {
        int a, b, l;
        cin >> a >> b >> l;
        d[a][b] = l;
    }

    // Применяем алгоритм Флойда-Уоршелла для нахождения кратчайших путей
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }

    // Находим среднюю длину кратчайшего пути
    double sum = 0.0;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (d[i][j] != INF && i != j) {
                sum += d[i][j];
                cnt++;
            }
        }
    }
    double ans = sum / cnt;

    // Выводим результат с точностью до 6 знаков после запятой
    printf("%.6f", ans);

    return 0;
}

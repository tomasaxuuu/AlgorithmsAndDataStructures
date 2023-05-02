#include <iostream>
#include <vector>

using namespace std;

bool dfs(int v, const vector<vector<int>>& adj, vector<int>& color) {
    color[v] = 1;
    for (int u = 0; u < adj.size(); u++) {
        if (adj[v][u]) {
            if (color[u] == 0) {
                if (dfs(u, adj, color)) {
                    return true;
                }
            }
            else if (color[u] == 1) {
                return true;
            }
        }
    }
    color[v] = 2;
    return false;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> adj(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> adj[i][j];
        }
    }

    vector<int> color(n, 0);
    bool has_cycle = false;
    for (int i = 0; i < n; i++) {
        if (color[i] == 0 && dfs(i, adj, color)) {
            has_cycle = true;
            break;
        }
    }

    if (has_cycle) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }

    return 0;
}

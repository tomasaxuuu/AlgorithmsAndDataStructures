#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <cmath>
#include <complex>
#include <vector>
#include <functional>
#include <string>

#define endl '\n'

typedef long long ll;

using namespace std;

const int MOD = 1e9 + 7;
const double EPS = 1e-9;

int n, m, v_cycle = -1;
vector<int> g[200100], order; 
int used[200100], pr[200100]; 

void dfs_orcycle(int v, int parent = -1) 
{
	if (used[v] == 2 || v_cycle != -1)
		return;
	pr[v] = parent;

	if (used[v])
	{
		v_cycle = v;
		return;
	}

	used[v] = 1;

	for (int to : g[v])
		dfs_orcycle(to, v);
	used[v] = 2; 
}

void topsort(int v)
{
	if (used[v])
		return;
	used[v] = 1;

	for (int to : g[v])
	{
		topsort(to);
	}

	order.push_back(v); 
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
	}

	for (int v = 0; v < n; ++v)
	{
		if (!used[v] && v_cycle == -1)
			dfs_orcycle(v);
	}

	fill(used, used + n, 0);

	if (v_cycle == -1) 
	{
		for (int v = 0; v < n; ++v)
		{
			if (!used[v])
				topsort(v);
		}

		reverse(order.begin(), order.end()); 

		for (int i = 0; i < order.size(); ++i)
		{
			cout << order[i] << ' ';
		}
	}
	else
	{
		cout << - 1 << endl;
	}

	return 0;
}
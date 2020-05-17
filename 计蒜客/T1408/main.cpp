#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;


const int MAX_LEN = 1e3 + 15;
pair<int, int> a[MAX_LEN];
int b[MAX_LEN][MAX_LEN];
int c[MAX_LEN];
int t, n;


int gt(pair<int, int> l, pair<int, int> r) {
	if (l.first < r.first & l.second < r.second)
		return true;
	if (l.first < r.second & l.second < r.first)
		return true;
	return false;
}


int solve(int p) {
	if (c[p] >= 0)
		return c[p];

	int r = 0;
	for (int j = 0; j < n; j++)
		if (b[p][j])
			r = max(r, solve(j) + 1);

	c[p] = r;
	return r;
}


int main() {
	// freopen("in.txt", "r", stdin);

	cin >> t;
	while (t--) {
		cin >> n;

		memset(b, 0, sizeof(b));
		memset(c, -1, sizeof(c));

		for (int i = 0; i < n; i++)
			cin >> a[i].first >> a[i].second;

		// cout << "\n";
		// for (int i = 0; i < n; i++)
		// 	cout << a[i].first << " " << a[i].second << endl;


		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (gt(a[i], a[j]))
					b[i][j] = 1;

		// cout << "\n";
		// for (int i = 0; i < n; i++) {
		// 	for (int j = 0; j < n; j++)
		// 		cout << b[i][j] << " ";
		// 	cout << "\n";
		// }

		int q = 0;
		for (int i = 0; i < n; i++)
			q = max(q, solve(i));
		cout << q + 1 << endl;

	}

	return 0;
}

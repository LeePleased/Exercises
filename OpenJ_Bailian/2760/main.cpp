#include <iostream>
using namespace std;

const int MAX_LEN = 100 + 15;
int a[MAX_LEN][MAX_LEN];
int n;

int main() {
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);

	while (cin >> n) {
		for (int i = 0; i < n; i++) 
			for (int j = 0; j <= i; j++)
				cin >> a[i][j];

		for (int i = 1; i < n; i++) {
			a[i][0] += a[i - 1][0];
			for (int j = 1; j <= i; j++)
				a[i][j] += max(a[i - 1][j - 1], a[i - 1][j]);
		}

		int r = a[n - 1][0];
		for (int k = 1; k < n; k++) 
			r = max(r, a[n - 1][k]);
		cout << r << endl;
	}

	return 0;
}

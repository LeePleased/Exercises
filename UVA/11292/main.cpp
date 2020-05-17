#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_LEN = 20000 + 15;
int a[MAX_LEN];
int b[MAX_LEN];


int main(){
	// freopen("in.txt","r",stdin);
	// freopen("out.txt","w",stdout);

	int n, m;
	while (cin >> n >> m) {
		if (!n & !m) 
			break;

		for (int i = 0; i < n; i++) 
			cin >> a[i];
		for (int j = 0; j < m; j++)
			cin >> b[j];

		sort(a, a + n);
		sort(b, b + m);

		int s = 0, k = 0, i = 0, j = 0;
		for (i = 0; i < n; i++) {
			while (k < m) {
				k += 1;
				if (b[k - 1] >= a[i]) {
					s += b[k - 1];
					j += 1;
					break;
				}
			}
			if (k >= m)
				break;
		}

		if (j == n) 
			cout << s << "\n";
		else
			cout << "Loowater is doomed!\n";
	}

	return 0;
}

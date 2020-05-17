#include <iostream>
#include <cstdlib>
using namespace std;

const int MAX_LEN = 100 + 15;
int a[MAX_LEN][MAX_LEN];
int b[MAX_LEN][MAX_LEN];
int n;
int p, q;

int solve(int x, int y) {
	if (b[x][y] != -1) 
		return b[x][y];
	return b[x][y] = (x == n - 1 ? a[x][y] : max(a[x][y], max(solve(x + 1, y), solve(x + 1, y + 1))));

	if (x == n - 1) 
		return b[x][y] = a[x][y];

}

int main() {
	// freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);

    while (cin >> n) {
    	if (!n) 
    		break;

    	for (int i = 0; i < n; i++) 
    		for (int j = 0; j <= i; j++) 
    			cin >> a[i][j];
    	cin >> p >> q;
    	
    	for (int i = 0; i < n; i++) 
    		for (int j = 0; j <= i; j++) 
    			b[i][j] = -1;
    	cout << solve(p - 1, q - 1) << endl;
    }

	return 0;
}

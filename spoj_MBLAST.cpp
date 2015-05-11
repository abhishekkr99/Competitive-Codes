// SHAKY99

#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define getcx getchar_unlocked

inline ll inp()
{
char g=0;
ll f=0;
while((g=getchar_unlocked())<48);
f=f*10+g-48;
while((g=getchar_unlocked())>=48)
f=f*10+g-48;
return f;
}

int dp[2001][2001];

int main() {
	char a[2001], b[2001], c[2001], d[2001];
	int i, j, size;

	scanf("%s %s %d", a, b, &size);

	memset(dp, -1, sizeof(dp));
	int n = strlen(a);
	int m = strlen(b);

/*	for (i = 1; i <= n; i++) {
		a[i] = c[i-1];
	}
	for (i = 1; i <= m; i++) {
		b[i] = d[i-1];
	}
*/
	for (i = 0; i <= n; i++) {
		dp[i][0] = size * i;
	}
	for (i = 0; i <= m; i++) {
		dp[0][i] = size * i;
	}
/*	
	for (i = 0; i <= m; i++) {
		for (j = 0; j <= n; j++) {
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
		
		cout << endl;
*/
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) {
//			cout << abs(a[i] - b[j]) << " " << a[i] << "" << b[j] << endl;
			int x = dp[i-1][j-1] + abs(a[i - 1] - b[j - 1]);
			int y = min(dp[i-1][j], dp[i][j-1]) + size;
			dp[i][j] = min(x, y);
//			cout << x << " " << y << "   " ;  
		}
//		cout << endl;
	}
/*	for (i = 0; i <= n; i++) {
		for (j = 0; j <= m; j++) {
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
*/	
	cout << dp[n][m] << endl;
}

#include <iostream>
#include <cstdio>

using namespace std;

const int INF = 9999999;
int dp[110][1200];

int main() {
	int t; scanf( "%d", &t );

	while( t-- ) {
		int n; scanf( "%d", &n );

		for( int i = 1; i <= n; i++ ) {
			for( int j = 0; j <= 1100; j++) {
				dp[i][j] = INF;
			}
		}

		for( int i = 1; i <= n; i++ ) {
			int cnt;
			scanf( "%d", &cnt );
			for( int j = 0; j < cnt; j++ ) {
				int bw, p;
				scanf( "%d %d", &bw, &p );
				if( i == 1 ) {
					dp[i][bw] = min( dp[i][bw], p );
				}
				else {
					for( int k = 0; k <= 1100; k++ ) {
						if( k <= bw ) {
							dp[i][k] = min( dp[i][k], dp[i-1][k] + p );
						}
						else
							dp[i][bw] = min( dp[i][bw], dp[i-1][k] + p );
					}
				}
			}
		}
		double ans = 0.0;
		for( int i = 0; i <= 1100; i++ ) {
			if( dp[n][i] != INF ) {
				ans = ans < i * 1.0 / dp[n][i] ? i * 1.0 / dp[n][i] : ans;
			}
		}
		printf( "%.3lf\n", ans );
	}
}
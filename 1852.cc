#include <iostream>
#include <cstdio>

using namespace std;

const int maxn = 1000000 + 10;

int main() {
	int t; scanf( "%d", &t );
	int len, n;
	int ants[maxn];
	while( t-- ) {
		scanf( "%d %d", &len, &n );
		
		int earliest_time, latest_time;
		earliest_time =	latest_time = -1;
		for( int i = 0; i < n; i++ ) {
			scanf( "%d", &ants[i] );
			earliest_time = max( earliest_time, min( ants[i], len - ants[i] ) );
			latest_time = max( latest_time, max( ants[i], len - ants[i] ) );
		}

		printf( "%d %d\n", earliest_time, latest_time );
	}
	return 0;
}

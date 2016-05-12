#include <iostream>
#include <cstdio>

using namespace std;

int num[100005];

int getMultiSum( int st, int ed ) {
	for( int i = st; i <= ed; i++ ) {
		sum[i][j] = max( sum[i][j-1], sum[i][j-1] + num[j] );
	}
}

int main() {
	int n;
	while( scanf( "%d", &n ), n ) {
		for( int i = 0; i < n; i++ ) {
			scanf( "%d", &num[i] );
		}
	}
}
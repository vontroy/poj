#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

const int maxn = 1000 + 5;

typedef struct node{
	double x;
	double y;
}island;

island isl[maxn];
double circles[maxn];

bool cmp( island a, lsland b ) {
	return a.x < b.x;
}

double getCircle( double x, double y, int d ) {
	return x + sqrt( d * d - y * y * 1.0 );
}

bool inCircle( double x, double y, double circle, int d ) {
	return y * y + ( x - circle ) * ( x - circle ) <= d * d * 1.0;
}

int main() {
	int n, d;
	int cas = 1;
	bool isVal = true;

	while( scanf( "%d%d", &n, &d ), n || d ) {
		isVal = true;
		for( int i = 0; i < n; i++ ){
			scanf( "%lf%lf", &isl[i].x, &isl[i].y );
			if( isl[i].y > d )
				isVal = false;
		}

		if( !isVal ){
			printf( "Case %d: %d\n", cas++, -1 );
			continue;
		}

		int num_of_circle = 0;
		bool flag = false;

		sort( isl, isl + n, cmp );

		for( int i = 0; i < n; i++ ) {
			flag = false;
			
			for( int j = 0; j < num_of_circle; j++ ) {
				if( inCircle( isl[i].x, isl[i].y, circles[j], d ) ) {
					flag = true;
					continue;
				}
			}
			
			if( !flag ) {
				circles[num_of_circle++] = getCircle( isl[i].x, isl[i].y, d );
			}
		}

		printf( "Case %d: %d\n", cas++, num_of_circle );
	}
	return 0;
}

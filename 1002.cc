#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

const int maxn = 50;
const int maxnums = 100000 + 10;

char trans( char ch ) {
	if( ch == 'A' || ch == 'B' || ch == 'C' ) return '2';
	else if( ch == 'D' || ch == 'E' || ch == 'F' ) return '3';
	else if( ch == 'G' || ch == 'H' || ch == 'I' ) return '4';
	else if( ch == 'J' || ch == 'K' || ch == 'L' ) return '5';
	else if( ch == 'M' || ch == 'N' || ch == 'O' ) return '6';
	else if( ch == 'P' || ch == 'R' || ch == 'S' ) return '7';
	else if( ch == 'T' || ch == 'U' || ch == 'V' ) return '8';
	else if( ch == 'W' || ch == 'X' || ch == 'Y' ) return '9';
	else if( ch >= '0' && ch <= '9' ) return ch;
	else return '-';
}

string ConvertToNum( char str[] ) {
	char ch_res[10];
	int cnt = 0;
	string res;
	for( int i = 0; str[i] != '\0'; i++ ) {
		char tmp = trans( str[i] );
		if( tmp != '-' )
			ch_res[cnt++] = tmp;
		if( cnt == 3 )
			ch_res[cnt++] = '-';
	}
	ch_res[cnt] = '\0';
	res = ch_res;
	return res;
}

int main() {
	int n; scanf( "%d", &n );
	char str[maxn];
	string ans[maxnums];

	map<string, int> strMap;
	map<string, int> :: iterator it;

	int cnt = 0;
	while( n-- ) {
		scanf( "%s", str );
		string tmp = ConvertToNum( str );

		it = strMap.find( tmp );

		if( it != strMap.end() ) {
			strMap[tmp]++;
		}
		else {
			strMap.insert( pair<string, int>( tmp, 1 ) );
			ans[cnt++] = tmp;
		}
	}

	sort( ans, ans + cnt );

	bool flag = false;
	for( int i = 0; i < cnt; i++ ) {
		if( strMap[ans[i]] >= 2 ) {
			printf( "%s %d\n", ans[i].c_str(), strMap[ans[i]] );
			flag = true;
		}
	}
	if( !flag )
		printf( "No duplicates.\n" );

	return 0;
}
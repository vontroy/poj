#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>

using namespace std;

const int maxn = 10050;

bool judge( string a, string b )
{
    int len = a.length();
    for( int i = 0; i < len; i++ )
    {
        if( a[i] != b[i] )
            return false;
    }
    return true;
}

int main()
{
    string num[maxn];
    int t; scanf( "%d", &t );
    int n;
    bool flag = 0;

    while( t-- )
    {
        flag = 0;
        scanf( "%d", &n );
        for( int i = 0; i < n; i++ )
        {
            cin >> num[i];
        }
        sort( num, num + n );

        for( int i = 0; i < n; i++ )
        {
            if( judge( num[i], num[i+1] ) )
            {
                printf( "NO\n" );
                flag = 1;
                break;
            }
        }
        if( !flag )
            printf( "YES\n" );
    }
    return 0;
}
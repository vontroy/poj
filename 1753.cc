#include <iostream>
#include <cstdio>

using namespace std;

const int maxn = 5;

bool mp[maxn][maxn];
bool flag = false;
int step;

bool is_same_color()
{
    for( int i = 0; i < 4; i++ )
    {
        for( int j = 0; j < 4; j++ )
        {
            if( mp[i][j] != mp[0][0] )
                return false;
        }
    }
    return true;
}

void flip( int row, int col )
{
    mp[row][col] = !mp[row][col];
    if( col - 1 >= 0 )
        mp[row][col-1] = !mp[row][col-1];
    if( row - 1 >= 0 )
        mp[row-1][col] = !mp[row-1][col];
    if( col + 1 < 4 )
        mp[row][col+1] = !mp[row][col+1];
    if( row + 1 < 4 )
        mp[row+1][col] = !mp[row+1][col];
}

void dfs( int row, int col, int step_cnt )
{
    if( step_cnt == step || flag )
        return;

    flip( row, col );
    flag = is_same_color();   //翻一次就检查一次

    if( col + 1 < 4 )
    {
        dfs( row, col + 1, step_cnt + 1 );
    }
    else if( row + 1 < 4 )
    {
        dfs( row + 1, 0, step_cnt + 1 );
    }
    flip( row, col );

    if( col + 1 < 4 )
    {
        dfs( row, col + 1, step_cnt );
    }
    else if( row + 1 < 4 )
    {
        dfs( row + 1, 0, step_cnt );
    }

    return;
}

int main()
{
    char ch;
    for( int i = 0; i < 4; i++ )
    {
        for( int j = 0; j < 4; j++ )
        {
            cin >> ch;
            if( ch == 'w' )
                mp[i][j] = false;
            else if( ch == 'b' )
                mp[i][j] = true;
        }
    }

    for( step = 0; step <= 16; step++ )
    {
        flag = is_same_color(); //翻之前先检查

        dfs( 0, 0, 0 );

        if( flag )
            break;
    }

    if( flag )
        printf( "%d\n", step );
    else
        printf( "Impossible\n" );

    return 0;
}
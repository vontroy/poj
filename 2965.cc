#include <iostream>
#include <cstdio>

using namespace std;

bool handles[5][5];

int step;

bool flag = false;

typedef struct node
{
    int row;
    int col;
}Path;

Path pt[20];

void change( int row, int col )
{
    for( int i = 0; i < 4; i++ )
    {
        handles[row][i] = !handles[row][i];
        handles[i][col] = !handles[i][col];
    }
    handles[row][col] = !handles[row][col];
}

bool allOpen()
{
    for( int i = 0; i < 4; i++ )
    {
        for( int j = 0; j < 4; j++ )
        {
            if( !handles[i][j] )
                return false;
        }
    }
    return true;
}

void dfs( int row, int col, int deep )
{
    if( flag || deep == step )
        return;

    change( row, col );
    flag = allOpen();

    pt[deep].row = row + 1;
    pt[deep].col = col + 1;

    if( col + 1 < 4 )
        dfs( row, col + 1, deep + 1 );
    else if( row + 1 < 4 )
        dfs( row + 1, 0, deep + 1 );

    change( row, col );

    if( col + 1 < 4 )
        dfs( row, col + 1, deep );
    else if( row + 1 < 4 )
        dfs( row + 1, 0, deep );
}

int main()
{
    char ch;
    for( int i = 0; i < 4; i++ )
    {
        for( int j = 0; j < 4; j++ )
        {
            scanf( "%c", &ch );
            if( ch == '-' )
                handles[i][j] = 1;
            else if( ch == '+' )
                handles[i][j] = 0;
        }
        getchar();
    }
    /*for( int i = 0; i < 4; i++ )
    {
        for( int j = 0; j < 4; j++ )
            printf( "%d ", handles[i][j] );
        printf( "\n" );
    }*/

    for( step = 1; step <= 16; step++ )
    {
        dfs( 0, 0, 0 );
        if( flag )
            break;
    }

    if( flag )
    {
        printf("%d\n", step);
        for (int i = 0; i < step; i++)
        {
            printf("%d %d\n", pt[i].row, pt[i].col);
        }
    }

    return 0;
}
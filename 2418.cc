#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

const int maxn = 130;

struct node
{
	int flag;
	int num;
	node* next[maxn];
};

struct res
{
	string str;
	int per;
}ans[10050];

map<string, int> myMap;

node* newnode()
{
	node* p = new node;
	p->flag = 0;
	p->num = 0;

	for( int i = 0; i < maxn; i++ )
		p->next[i] = NULL;

	return p;
}

void trie_insert( node* root, char* s )
{
	node* p = root;
	int len = strlen( s );

	int tmp;
	for( int i = 0; i < len; i++ )
	{
		tmp = (int) s[i];
		if( p->next[tmp] == NULL )
			p->next[tmp] = newnode();
		p = p->next[tmp];
	}

	p->flag = 1;
	p->num++;
	myMap[s] = p->num;
}

int trie_search( node* root, char* s )
{
	node* p = root;
	int len = strlen( s );

	int tmp;
	for( int i = 0; i < len; i++ )
	{
		tmp = (int) s[i];
		if( p->next[tmp] == NULL )
			return 0;
		p = p->next[tmp];
	}

	if( p->flag )
	{
		p->num++;
		myMap[s] = p->num;
		return 1;
	}

	p->flag = 1;
	p->num++;
	myMap[s] = p->num;
	return 2;
}

int cmp( res a, res b )
{
	return a.str < b.str;
}

int main()
{
	char str[35];
	int len;
	double sum = 0.0;
	
	node* root = newnode();

	while( gets( str ) )
	{
		sum += 1.0;
		len = strlen( str );
		
		int f = trie_search( root, str );

		if( f == 0 )
		{
			trie_insert( root, str );
		}
	}

	map<string, int>::iterator it;

	int ind = 0;
	for( it = myMap.begin(); it != myMap.end(); it++ )
	{
		ans[ind].str = it->first;
		ans[ind++].per = it->second;
	}

	sort( ans, ans + ind, cmp );

	for( int i = 0; i < ind; i++ )
	{
		printf( "%s %.4lf\n", ans[i].str.c_str(), ans[i].per * 100.0 / sum );
	}

	return 0;
}
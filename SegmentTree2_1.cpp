#include "bits/stdc++.h"
using namespace std ;
const int MAX = 1e5+5 ;
int n , m , t[ MAX << 1 ] ; 
void update ( int i , int v )
{
	for ( t[ i += n ] = v ; i != 1 ; i >>= 1 )
	{
		t[ i >> 1 ] = min ( t[i] , t[i^1] ) ; //when i%2==0 i^1 is i++ ex 6^1=7
	}
}

int query ( int l , int r )
{
	int mn = 1e9 ;
	for ( l += n , r += n ; l < r ; l >>= 1 , r >>= 1 )
	{
		if ( l & 1 ) mn = min ( mn , t[l++] ) ; //l&1 is l%2==1
		if ( r & 1 ) mn = min ( mn , t[--r] ) ;
	}
	return mn ;
}

void build () 
{
	for ( int i = n-1 ; i ; i-- )
	{
		t[i] = min ( t[ i << 1 ] , t[ i << 1 | 1 ] ) ;
	}
}

int main ()
{
	int st , ed ;
	cin >> n >> st >> ed ;
	for ( int i = 0 ; i < n ; i++ )	scanf ( " %d " , t+n+i ) ;
	build () ;
	cout << query ( st-1 , ed );
}
// https://codeforces.com/blog/entry/18051
//index start at 1

/*
5 1 5
3
4
5
6
-10
OUTPUT = -10
*/
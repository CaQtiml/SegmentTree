#include "bits/stdc++.h"
using namespace std ;
const int MAX = 1e5+5 ;
int n , m , t[ MAX << 1 ] ; 
void update ( int i , int v )
{
	for ( t[ i += n ] = v ; i != 1 ; i >>= 1 )
	{
		t[ i >> 1 ] = min ( t[i] , t[i^1] ) ;
	}
}

int query ( int l , int r )
{
	int mn = 1e9 ;
	for ( l += n , r += n+1 ; l < r ; l >>= 1 , r >>= 1 )
	{
		if ( l & 1 ) mn = min ( mn , t[l++] ) ;
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
	cin >> n ;
	for ( int i = 0 ; i < n ; i++ )	scanf ( " %d " , t+n+i ) ;
	build () ;
	cout << query ( 1 , 5 );
}
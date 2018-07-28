#include "bits/stdc++.h"
using namespace std;
#define MAX 1e7
int n , t [ 1 << 18 ] ;
void update ( int i , int val )
{
	for ( t [ i += n ] = val ; i != 1 ; i >>= 1 )
	{
		t[ i >> 1 ] = t[ i ] + t[ i ^ 1 ] ;
	}
}
int query ( int l , int r )
{
	int sum = 0;
	for ( l += n , r += n+1 ; l < r ; l >>= 1 , r >>= 1 )
	{
		if ( l & 1 ) sum =  sum + t[l++]  ;   
		if ( r & 1 ) sum =  sum + t[--r]  ;   
	}
	return sum ;
}
void build () 
{
	for ( int i = n ; i ; i-- )
	{
		t[i] = t[ i << 1 ] + t [ i << 1 | 1 ] ;
	}
}
int main ()
{
	int st , ed ;
	cin >> n >> st >> ed ;
	for ( int i = 1 ; i <= n ; i++ )	scanf ( " %d " , t+n+i ) ;
	build () ;
	cout << query ( st , ed ) ;
}

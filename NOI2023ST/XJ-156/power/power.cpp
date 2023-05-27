#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>

#include <vector>
#include <algorithm>

typedef const int cint;
typedef long long ll;
typedef unsigned long long ull;
typedef const long long cll;
typedef __int128 lll;
typedef const __int128 clll;

const int K = 100;
const int N = 1e6 + 5;

/*{{{*/
inline bool is_number( const char cur ) { return cur >= '0' && cur <= '9'; }
template <class T>
T read() {
	int k = 1; char x = getchar(); T res = 0;
	for( ; !is_number(x); x = getchar() ) 
		if( x == '-' ) 
			k = -1;
	for( ; is_number(x); x = getchar() )
		res = res * 10 + ( x - '0' );
	return res * k;
}

template <class T>
T Min( T a, T b ) { return a < b? a: b; }
template <class T>
T Max( T a, T b ) { return a > b? a: b; }
template <class T>
void chk_Min( T &a, T b ) { if( a > b ) a = b; }
template <class T>
void chk_Max( T &a, T b ) { if( a < b ) a = b; }

template <class T>
T pow( T a, int p ) {
	T res = 1;
	while(p) {
		if( p & 1 ) 
			res *= a;
		a *= a;
		p >>= 1;
	}
	return res;
}/*}}}*/

ll sqrtp[ K + 5 ];

// int check( ull a, int p ) {
// 	int res = (int)std::floor( std::pow( a, (double)1 / p ) );
// 	while( pow( (unsigned __int128) res, p ) > a )
// 		res --;
// 	while( pow( (unsigned __int128) res + 1, p ) <= a ) {
// 		res ++;
// 	}
// 	return res;
// 	//return (ll)std::floor(std::pow( a, (double)1/ p ));
// }

std::vector<int> primes;
void init( cll n ) {
	sqrtp[0] = N - 1;
	{ // calculate a^{1/p} which p > 2, calculate p = 2 down{{{
		static lll current_ap[N];
		cll limit = Min( n, (ll)1e18 );
		for( int i = 1; i < N; i ++ ) 
			current_ap[i] = 1;
		for( int i = 1; i <= K; i ++ )  {
			for( int j = 1; j < N; j ++ ) {
				if( current_ap[j] > limit ) 
					break;
				current_ap[j] *= j;
			}
			for( int j = sqrtp[ i - 1 ]; j >= 1; j -- ) {
				if( current_ap[j] <= n ) {
					sqrtp[i] = j;
					break;
				}
			}
		}
	}/*}}}*/

	{ // use binary search to find sqrt(a) cause sqrt(a) may large then 1e6{{{
		int left = 1, rig = (int)1e9, res = 1;
		while( left <= rig ) {
			cint mid = ( left + rig ) >> 1;
			if( pow( (lll)mid, 2 ) <= (lll)n ) {
				res = mid;
				left = mid + 1;
			}
			else
				rig = mid - 1;
		}
		sqrtp[2] = res;
	}/*}}}*/

	sqrtp[1] = n;
}

int main() {
	freopen( "power.in", "r", stdin );
	freopen( "power.out", "w", stdout );

	cll n = read<ll>();
	cint k = read<int>();

	init(n);

	std::vector<ll> f( K + 1, 0 );

	for( int i = K; i >= k; i -- ) {
		f[i] += sqrtp[i] - 1;
		for( int j = 2; j <= K; j ++ ) 
			if( i % j == 0 ) 
				f[ i / j ] -= f[i];
	}

	ll res = 0;
	for( int i = k; i <= K; i ++ ) {
		// printf( "%lld\n", f[i] );
		res += f[i];
	}

	printf( "%lld\n", res + 1 );

	fclose( stdin );
	fclose( stdout );
	return 0;
}

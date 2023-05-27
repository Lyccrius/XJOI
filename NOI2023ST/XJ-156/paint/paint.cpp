#include <cstdio>
#include <cstring>
#include <cstdlib>

#include <vector>
#include <algorithm>

typedef const int cint;
typedef long long ll;
typedef unsigned long long ull;
typedef const long long cll;

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

int main() {
	freopen( "paint.in", "r", stdin );
	freopen( "paint.out", "w", stdout );

	int T = read<int>();
	while( T -- ) { 
		cint n = read<int>();
		cint m = read<int>();
		cint q = read<int>();

		struct Event { int time, col; };
		std::vector<Event> x( n + 1 ), y( m + 1 );

		for( int idx = 1; idx <= q; idx ++ ) {
			cint op = read<int>();
			cint id = read<int>();
			cint col = read<int>();
			
			if( op == 0 ) {
				x[id] = (Event) { idx, col };
			}
			if( op == 1 ) {
				y[id] = (Event) { idx, col };
			}
		}
		for( int i = 1; i <= n; i ++ ) {
			for( int j = 1; j <= m; j ++ ) {
				int col = x[i].time > y[j].time? x[i].col: y[j].col;
				printf( "%d", col );
				if( j != m )
					printf( " " );
			}
			printf( "\n" );
		}
		
	}
	
	fclose( stdin );
	fclose( stdout );
	return 0;
}

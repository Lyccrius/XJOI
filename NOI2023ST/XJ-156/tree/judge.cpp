#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>

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

const int N = 1e4 + 1e3;

struct Node {
	int id;
	double x, y;
} ori[N];

double dis( Node from, Node to ) { return std::sqrt( ( from.x - to.x ) * ( from.x - to.x ) + ( from.y - to.y ) * ( from.y - to.y ) ); }

int main() {
	FILE* input = fopen( "tree.in", "r" );
	FILE* output = fopen( "tree.out", "r" );
	FILE* answer = fopen( "tree.ans", "r" );

	int n = 0;
	int f1 = 0, f2 = 0;
	double res = 0;
	fscanf( input, "%d", &n );
	for( int i = 1; i <= n; i ++ ) {
		fscanf( input, "%lf%lf", &ori[i].x, &ori[i].y );
	}
	int la = -1;
	for( int i = 1; i <= n; i ++ ) {
		int x = 0;
		fscanf( answer, "%d", &x );
		if( la != -1 ) {
			f1 = x;
			res += dis( ori[la], ori[x] );
		}
		la = x;
	}

	la = -1;
	double res2 = 0;
	for( int i = 1; i <= n; i ++ ) {
		int x = 0;
		fscanf( output, "%d", &x );
		if( la != -1 ) {
			f2 = x;
			res2 += dis( ori[la], ori[x] );
		}
		la = x;
	}

	printf( "%d %d\n", f1, f2 );
	printf( "%.10lf\n", res );
	printf( "%.10lf\n", res2 );

	fclose( stdin );
	fclose( stdout );
	return 0;
}

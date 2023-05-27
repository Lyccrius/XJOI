#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>

#include <algorithm>

typedef const int cint;
typedef long long ll;
typedef unsigned long long ull;
typedef const long long cll;

const int N = 1e3 + 1e2;

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
bool chk_Min( T &a, T b ) { 
	if( a > b ) { 
		a = b; 
		return true;
	}
	return false;
}
template <class T>
bool chk_Max( T &a, T b ) { 
	if( a < b ) { 
		a = b; 
		return true;
	}
	return false;
}

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

double f[N][N][3];

struct Node {
	int id;
	double x, y;
} ori[N], cir[2][N];

struct Op {
	int i, j, k;
} la[N][N][3];

double dis( Node from, Node to ) { return std::sqrt( ( from.x - to.x ) * ( from.x - to.x ) + ( from.y - to.y ) * ( from.y - to.y ) ); }

double dis( cint kind, cint from, cint to ) {
	if( kind == 1 ) 
		return dis( cir[0][from], cir[0][to] );
	if( kind == 2 ) 
		return dis( cir[1][from], cir[1][to] );
	if( kind == 3 ) 
		return dis( cir[0][from], cir[1][to] );
	return 0.0;
}

void print( Op cur ) {
	if( cur.k == 0 ) {
		if( cur.i != 0 ) 
			for( int i = 0; i <= cur.i; i ++ ) 
				printf( "%d ", cir[0][i].id );
		if( cur.j != 0 ) 
			for( int i = 0; i <= cur.j; i ++ ) 
				printf( "%d ", cir[1][i].id );
	}
	if( cur.k == 1 ) {
		const auto last = la[ cur.i ][ cur.j ][ cur.k ];
		print(last);
		printf( "%d ", cir[0][ cur.i ].id );
	}
	if( cur.k == 2 ) {
		const auto last = la[ cur.i ][ cur.j ][ cur.k ];
		print(last);
		printf( "%d ", cir[1][ cur.j ].id );
	}
}

int main() {
	freopen( "tree.in", "r", stdin );
	freopen( "tree.out", "w", stdout );

	cint n = read<int>();
	int k = 0;
	double res = 0;
	for( int i = 0; i < n; i ++ ) {
		scanf( "%lf%lf", &ori[i].x, &ori[i].y );
		ori[i].id = i + 1;
		if( ori[i].y > ori[k].y )
			k = i; 
	}
	for( int i = 0; i < n; i ++ ) {
		cir[0][i] = ori[ ( k + i ) % n ];
		if( i == 0 ) 
			cir[1][0] = cir[0][0];
		else {
			res += dis( cir[0][i], cir[0][ i - 1 ] );
			cir[1][ n - i ] = cir[0][i];
		}
	}
	
	res = 1e10;

	for( int i = 0; i < n; i ++ ) {
		for( int j = 0; j < n; j ++ ) {
			f[i][j][0] = res;
			f[i][j][1] = res;
			f[i][j][2] = res;
		}
	}
	f[0][0][0] = 0;


	for( int i = 0; i < n; i ++ ) {/*{{{*/
		for( int j = 0; j < n; j ++ ) {
			if( i - 1 >= 0 && j == 0 ) 
				if( chk_Min( f[i][j][0], f[ i - 1 ][j][0] + dis( 1, i - 1, i ) ) )
					la[i][j][0] = (Op){ i - 1, j, 0 };
			if( j - 1 >= 0 && i == 0 )
				if( chk_Min( f[i][j][0], f[i][ j - 1 ][0] + dis( 2, j - 1, j ) ) )
					la[i][j][0] = (Op){ i, j - 1, 0 };
			if( i - 1 >= 0 ) 
				if( chk_Min( f[i][j][1], f[ i - 1 ][j][1] + dis( 1, i - 1, i ) ) )
					la[i][j][1] = (Op){ i - 1, j, 1 };
			if( j - 1 >= 0 )
				if( chk_Min( f[i][j][2], f[i][ j - 1 ][2] + dis( 2, j - 1, j ) ) )
					la[i][j][2] = (Op){ i, j - 1, 2 };

			if( i - 1 >= 0 && j != 0 ) 
				if( chk_Min( f[i][j][1], f[ i - 1 ][j][0] + dis( 3, i, j ) ) )
					la[i][j][1] = (Op){ i - 1, j, 0 };
			if( j - 1 >= 0 && i != 0 )
				if( chk_Min( f[i][j][2], f[i][ j - 1 ][0] + dis( 3, i, j ) ) )
					la[i][j][2] = (Op){ i, j - 1, 0 };

			if( j - 1 >= 0 )
				if( chk_Min( f[i][j][2], f[i][ j - 1 ][1] + dis( 3, i, j ) ) )
					la[i][j][2] = (Op){ i, j - 1, 1 };
			if( i - 1 >= 0 ) 
				if( chk_Min( f[i][j][1], f[ i - 1 ][j][2] + dis( 3, i, j ) ) )
					la[i][j][1] = (Op){ i - 1, j, 2 };
		}
	}/*}}}*/

	Op best = (Op) { 0, 0, 0 };
	for( int i = 0; i < n; i ++ ) {
		cint j = n - i - 1;
		if( chk_Min( res, f[i][j][0] ) ) 
			best = (Op) { i, j, 0 };
		if( chk_Min( res, f[i][j][1] ) )
			best = (Op) { i, j, 1 };
		if( chk_Min( res, f[i][j][2] ) )
			best = (Op) { i, j, 2 };
	}

	print(best);


	fclose( stdin );
	fclose( stdout );
	return 0;
}

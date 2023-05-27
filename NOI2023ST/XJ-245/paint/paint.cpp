#include<cstdio>
#include<algorithm>
#include<cstring>
#define F(i, a, b) for(int i = a;i <= b;i++)
#define R(i, a, b) for(int i = a;i >= b;i--)
using namespace std;
const int maxn = 1e5 + 5;
void read(int &f){
    char ch = getchar(); int w = 1;
    while (ch < '0' || ch > '9'){ if (ch == '-') w = -1; ch = getchar(); }
    for (f = 0;ch >= '0' && ch <= '9';f = f * 10 + ch - '0', ch = getchar());
    f *= w;
}
struct node{
    int col, tim;
}h[2][maxn];
int main(){
    freopen("paint.in", "r", stdin);
    freopen("paint.out", "w", stdout);
    int T; read(T);
    while (T--){
        int n, m, q; read(n); read(m); read(q);
        F(i, 1, max(n, m)) h[0][i].col = h[0][i].tim = h[1][i].col = h[1][i].tim = 0;
        F(i, 1, q){
            int t, a, b; read(t); read(a); read(h[t][a].col); h[t][a].tim = i;
        }
        F(i, 1, n){
            F(j, 1, m) printf("%d ", h[0][i].tim > h[1][j].tim ? h[0][i].col : h[1][j].col);
            puts("");
        }
    }
    return 0;
}
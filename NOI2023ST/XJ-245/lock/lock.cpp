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
int a[maxn][5];
int main(){
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    int T, k; read(T); read(k);
    while (T--){
        int n; read(n);
        F(i, 1, k) F(j, 1, n) read(a[j][i]);
        if (k == 1){
            int t1 = -1, t2 = 3e5;
            F(i, 1, n) t1 = max(t1, a[i][1]), t2 = min(t2, a[i][1]);
            printf("%d\n", t1 - t2);
        }
        else if (k == 2){
            int mn[4], mx[4], ans = -1;
            F(i, 1, k) mn[i] = 3e5, mx[i] = -1;
            F(i, 1, n) sort(a[i] + 1, a[i] + k + 1);
            F(j, 1, k) F(i, 1, n) mx[j] = max(mx[j], a[i][j]), mn[j] = min(mn[j], a[i][j]);
            F(i, 1, k) ans = max(ans, mx[i] - mn[i]);
            printf("%d\n", ans);
        }
    }
    return 0;
}
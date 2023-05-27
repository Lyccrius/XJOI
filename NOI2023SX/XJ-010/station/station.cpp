#include <cstdio>
#include <cstring>
#include <algorithm>
#define F(i, a, b) for(int i = a;i <= b;i++)
#define R(i, a, b) for(int i = a;i >= b;i--)
using namespace std;
const int maxn = 2e5 + 5;
void read(int &f){
    char ch = getchar(); int w = 1;
    while (ch < '0' || ch > '9'){
        if (ch == '-') w = -1;
        ch = getchar();
    }
    for(f = 0;ch >= '0' && ch <= '9';f = (f << 3) + (f << 1) + ch - '0', ch = getchar());
    f *= w;
}
struct node{
    int l, r;
}a[maxn];
bool cmp1(node a, node b){
    return a.l == b.l ? a.r < b.r : a.l < b.l;
}
bool cmp2(node a, node b){
    return a.r == b.r ? a.l > b.l : a.r > b.r;
}
int ans[maxn], ansn, book[maxn];
int main(){
    freopen("station.in", "r", stdin);
    freopen("station.out", "w", stdout);
    int n, m, x; read(n); read(m); read(x);
    F(i, 1, m) read(a[i].l), read(a[i].r);
    sort(a + 1, a + m + 1, cmp1);
    int t = 1; while (a[t].r < x && t < m) t++;
    int maxr = a[t].r; if (maxr > x) ans[++ansn] = maxr, book[maxr] = 1;
    while (t < m && a[t + 1].l <= maxr){
        t++; maxr = max(maxr, a[t].r);
        if (a[t].r > x && !book[a[t].r])
            ans[++ansn] = a[t].r, book[a[t].r] = 1;
    }
    sort(a + 1, a + m + 1, cmp2);
    t = 1; while (a[t].l > x && t < m) t++;
    int minl = a[t].l; if (minl < x) ans[++ansn] = minl, book[minl] = 1;
    while (t < m && a[t + 1].r >= minl){
        t++; minl = min(minl, a[t].l);
        if (a[t].l < x && !book[a[t].l])
            ans[++ansn] = a[t].l, book[a[t].l] = 1;
    }
    sort(ans + 1, ans + ansn + 1);
    F(i, 1, ansn) printf("%d ", ans[i]);
    return 0;
}
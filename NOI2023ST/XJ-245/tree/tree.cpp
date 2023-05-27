#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#define F(i, a, b) for(int i = a;i <= b;i++)
#define R(i, a, b) for(int i = a;i >= b;i--)
using namespace std;
const int maxn = 1e3 + 5;
void read(int &f){
    char ch = getchar(); int w = 1;
    while (ch < '0' || ch > '9'){ if (ch == '-') w = -1; ch = getchar(); }
    for (f = 0;ch >= '0' && ch <= '9';f = f * 10 + ch - '0', ch = getchar());
    f *= w;
}
int n, ans[maxn], vis[maxn], a[maxn];
double x[maxn], y[maxn], ansdis = 1e9;
struct node{
    double ds;
    int a;
}book[300005];
void dfs(int nw, int step, double dis, int now){
    if (dis >= ansdis) return ;
    if (book[now].ds){
        if (dis + book[now].ds < ansdis){
            ansdis = dis + book[now].ds;
            F(i, 1, step - 1) ans[i] = a[i];
            F(i, step, n) ans[i] = book[now].a, now += 1 << (book[now].a - 1);
        }
        return ;
    }
    if (step == n + 1){
        ansdis = dis;
        F(i, 2, n) ans[i] = a[i];
        return ;
    }
    F(i, 1, n) if (!vis[i]){
        vis[i] = 1; a[step] = i;
        dfs(i, step + 1, dis + sqrt((x[i] - x[nw]) * (x[i] - x[nw]) + (y[i] - y[nw]) * (y[i] - y[nw])), now + (1 << (i - 1)));
        vis[i] = 0; int t = book[now].ds;
        book[now].ds = min(book[now].ds, book[now + (1 << (i - 1))].ds + sqrt((x[i] - x[nw]) * (x[i] - x[nw]) + (y[i] - y[nw]) * (y[i] - y[nw])));
        if (book[now].ds != t) book[now].a = i;
    }
}
int main(){
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    read(n); int k = 0, tmp = 1; y[0] = -1e7 - 5;
    F(i, 1, n){
        scanf("%lf%lf", &x[i], &y[i]), y[i] > y[k] ? k = i : k = k;
        if (i > 1 && (x[i] < x[i - 1] || y[i] > y[i - 1])) tmp = 0;
    }
    if (n > 18 && tmp) { F(i, 1, n) printf("%d ", i); return 0; }
    vis[k] = 1; ans[1] = k; dfs(k, 2, 0, 1 << (k - 1));
    F(i, 1, n) printf("%d ", ans[i]);
    return 0;
}
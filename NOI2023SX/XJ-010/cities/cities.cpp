#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define F(i, a, b) for(int i = a;i <= b;i++)
#define R(i, a, b) for(int i = a;i >= b;i--)
#define Fe(i, u) for(int i = hd[u];i;i = e[i].nxt)
using namespace std;
const int maxn = 1e5 + 5;
void read(int &f){
    char ch = getchar(); int w = 1;
    while (ch < '0' || ch > '9'){
        if (ch == '-') w = -1;
        ch = getchar();
    }
    for(f = 0;ch >= '0' && ch <= '9';f = (f << 3) + (f << 1) + ch - '0', ch = getchar());
    f *= w;
}
struct Edge{
    int nxt, v;
}e[100];
int hd[20], tot, tmp, col[20], cnt, siz[20], book[30];
void add_edge(int u, int v){
    e[++tot] = (Edge){hd[u], v};
    hd[u] = tot;
}
int u[maxn], v[maxn];
void work(int i){
    int nw = 1;
    while (i){
        if (i & 1){
            add_edge(u[nw], v[nw]), add_edge(v[nw], u[nw]), tmp++;
            book[u[nw]] = book[v[nw]] = 1;
        }
        i >>= 1; nw++;
    }
}
void dfs(int nw, int k){
    Fe(i, nw){
        if (col[e[i].v]) continue;
        col[e[i].v] = cnt; siz[k]++;
        dfs(e[i].v, k);
    }
}
int main(){
    freopen("cities.in", "r", stdin);
    freopen("cities.out", "w", stdout);
    int n, m, k; read(n); read(m); read(k);
    F(i, 1, m) read(u[i]), read(v[i]);
    int ans = 0;
    F(i, 0, (1 << m) - 1){
        memset(hd, 0, sizeof(hd)); memset(e, 0, sizeof(e)); memset(col, 0, sizeof(col));
        tot = tmp = cnt = 0; memset(siz, 0, sizeof(siz)); memset(book, 0, sizeof(book));
        work(i); tmp = n - tmp;
        int tt = 0;
        F(j, 1, m) tt += book[j];
        if (n - tt != tmp) continue;
        F(j, 1, n) if (!col[j]) col[j] = ++cnt, siz[j] = 1, dfs(j, j);
        if (cnt == tmp){
            int f = 1;
            F(j, 2, cnt) if (siz[j - 1] != siz[j]) { f = 0; break; }
            ans += f;
        }
    }
    printf("%d", ans);
    return 0;
}
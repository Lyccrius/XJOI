#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define int long long
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
    int v, nxt;
}e[maxn * 2];
struct node{
    int x, y, id;
}a[maxn];
int tot, hd[maxn];
void add_edge(int u, int v){
    e[++tot] = (Edge){v, hd[u]};
    hd[u] = tot;
}
bool cmp(node a, node b) { return a.y > b.y; }
bool cmp2(int a, int b) { return a < b; }
int n, k, m, t, ans, vis[maxn], mn, mnx, cnt[maxn];
vector<int> book[maxn];
int work(int id){
    Fe(i, id){
        if (!book[e[i].v][cnt[e[i].v]]) return e[i].v;
        if (!vis[e[i].v])
            if (book[e[i].v][cnt[e[i].v]] < mn) mn = book[e[i].v][cnt[e[i].v]], mnx = e[i].v;
    }
    Fe(i, id) work(e[i].v);
    return 0;
}
signed main(){
    freopen("transfer.in", "r", stdin);
    freopen("transfer.out", "w", stdout);
    int sid; read(sid); read(n); read(k); read(m);
    F(i, 2, n) read(t), add_edge(t, i);
    F(i, 1, n) book[i].push_back(0);
    F(i, 1, k){
        read(a[i].x), read(a[i].y), a[i].id = i;
        book[a[i].x].push_back(a[i].y);
    }
    F(i, 1, n) sort(book[i].begin(), book[i].end(), cmp2), cnt[i] = 1;
    if (sid >= 6 && sid <= 18){
        sort(a + 1, a + k + 1, cmp);
        F(i, 1, k){
            mn = 1000000000, mnx = 0;
            if (!vis[a[i].x]) vis[a[i].x] = a[i].y;
            else{
                int tmp = work(a[i].x);
                if (!tmp) { if(mnx) vis[mnx] = a[i].y, cnt[a[i].x]++; }
                else vis[tmp] = a[i].y;
            }
        }
        F(i, 1, n) ans += vis[i];
        printf("%lld", ans);
    }
    return 0;
}
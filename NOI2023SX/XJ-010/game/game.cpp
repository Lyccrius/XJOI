#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#define F(i, a, b) for(int i = a;i <= b;i++)
#define R(i, a, b) for(int i = a;i >= b;i--)
#define Fe(i, u) for(int i = hd[u];i;i = e[i].nxt)
using namespace std;
const int maxn = 1e6 + 5;
void read(int &f){
    char ch = getchar(); int w = 1;
    while (ch < '0' || ch > '9'){
        if (ch == '-') w = -1;
        ch = getchar();
    }
    for(f = 0;ch >= '0' && ch <= '9';f = (f << 3) + (f << 1) + ch - '0', ch = getchar());
    f *= w;
}
int n, m, sn1[maxn], sn2[maxn], s1[maxn][3], s2[maxn][3], book[maxn], a[maxn], ans, tmp, a2[maxn];
int vis[205][205];
int work(int x){
    int sum = 0;
    F(i, 1, n){
        if (x % 2 && sn1[i] < 2) return 0;
        a2[i] = s1[i][(x & 1) + 1];
        x >>= 1;
    }
    return 1;
}
void dfs(int step, int nw){
    if (step == n + 1){
        int sum = 0;
        F(i, 1, n) if (a[i] == a2[i]) sum++;
        tmp = min(tmp, sum);
        return ;
    }
    F(i, 1, sn2[step]) if (!book[s2[step][i]])
        book[s2[step][i]] = 1, a[step] = s2[step][i], dfs(step + 1, nw), book[s2[step][i]] = 0;
}
int main(){
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    int T; read(T);
    while (T--){
        memset(book, 0, sizeof(book));
        memset(a, 0, sizeof(a));
        read(n); read(m); int f = 0;
        F(i, 1, n){
            read(sn1[i]);
            F(j, 1, sn1[i]) read(s1[i][j]);
        }
        F(i, 1, n){
            read(sn2[i]);
            F(j, 1, sn2[i]) read(s2[i][j]);
            if (s2[i][1] > s2[i][2]) swap(s2[i][1], s2[i][2]);
            if (i == n && s2[i][1] < s2[i][2]) swap(s2[i][1], s2[i][2]);
            if (s2[i][1] != i || s2[i][2] != (i + 1) && s2[i][2] != 1) f = 1;
        }
        if (n <= 11){
            ans = -1;
            F(i, 0, (1 << n) - 1){
                tmp = 1e9 + 7, memset(book, 0, sizeof(book));
                if (!work(i)) continue;
                dfs(1, i);  if (tmp != 1e9 + 7) ans = max(ans, tmp);
            }
            printf("%d\n", ans);
        }else{
            F(i, 1, n){
                int mx = -1;
                F(j, 1, sn1[i]){
                    int f = 0;
                    F(k, 1, sn2[i]) if (s1[i][j] == s2[i][k]) f++;
                    if (f > mx) a[i] = s1[i][j], mx = f;
                    if (f == mx) a[i] = book[s1[i][j]] ? s1[i][j] : a[i];
                }
                book[a[i]] = 1;
            }
            int sum1 = 0, sum2 = 0;
            F(i, 1, n){
                if (a[i] == s2[i][1]) sum1++;
                if (a[i] == s2[i][2]) sum2++;
            }
            printf("%d\n", min(sum1, sum2));
        }
    }
    return 0;
}
#include <cstdio>
#include <cstring>
#include <algorithm>
#define F(i, a, b) for(int i = a;i <= b;i++)
#define R(i, a, b) for(int i = a;i >= b;i--)
#define Fe(i, u) for(int i = hd[u];i;i = e[i].nxt)
using namespace std;
const int maxn = 55;
const int mod = 998244353;
void read(int &f){
    char ch = getchar(); int w = 1;
    while (ch < '0' || ch > '9'){
        if (ch == '-') w = -1;
        ch = getchar();
    }
    for(f = 0;ch >= '0' && ch <= '9';f = (f << 3) + (f << 1) + ch - '0', ch = getchar());
    f *= w;
}
int a[maxn], b[maxn], n, m, t, t1, t2, s[maxn], ss[maxn];
int work(int x){
    F(i, 1, n){
        ss[i] = x & 1;
        if (x & 1) a[++t1] = s[i];
        else b[++t2] = s[i];
        if (a[t1] <= a[t1 - 1] && t1 >= 2 || b[t2] >= b[t2 - 1] && t2 >= 2) return 1;
        x >>= 1;
    }
    return 0;
}
int main(){
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    int T; read(T);
    while (T--){
        memset(ss, 0, sizeof(ss));
        read(n); read(m); read(t);
        F(i, 1, t) read(s[i]);
        if (t == n){
            int ans1 = 0, ans = 0;
            F(i, 0, (1 << n) - 1){
                t1 = t2 = 0;
                if (work(i)) continue;
                ans1++; int ans2 = 0;
                F(j, 1, n) F(k, j + 1, n){
                    if (s[k] > s[j] && !ss[k]) ans2 += s[k], ans2 %= mod;
                    else if (s[k] < s[j] && ss[k]) ans2 += m - s[k] + 1, ans2 %= mod;
                }
                ans = max(ans, ans2);
            }
            if (ans1 < 2) puts("0\n0");
            else printf("1\n%d\n", ans);
        }else puts("1\n0");
    }
    return 0;
}
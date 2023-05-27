#include<cstdio>
#include<algorithm>
#include<cstring>
#define F(i, a, b) for(int i = a;i <= b;i++)
#define R(i, a, b) for(int i = a;i >= b;i--)
#define int long long
using namespace std;
const int maxn = 1e5 + 5;
void read(int &f){
    char ch = getchar(); int w = 1;
    while (ch < '0' || ch > '9'){ if (ch == '-') w = -1; ch = getchar(); }
    for (f = 0;ch >= '0' && ch <= '9';f = f * 10 + ch - '0', ch = getchar());
    f *= w;
}
int p[65], n, k;
int qpow(int a, int b, int pd){
    int ans = 1, tmp = a, tt = 0;
    while (b){
        if (b & 1ll){
            if (tt == 1 || ans >= pd / tmp + 1ll) return 1;
            else ans *= tmp;
        }
        if (tt == 1 || tmp >= pd / tmp + 1ll) tt = 1;
        else tmp *= tmp;
        b >>= 1ll;
    }
    return 0;
}
int sqr(int a, int b){
    int l = 1, r = a + 1, mid;
    while (l < r){
        int mid = l + r >> 1ll;
        if (qpow(mid, b, a)) r = mid;
        else l = mid + 1;
    }
    return l - 1;
}
signed main(){
    freopen("power.in", "r", stdin);
    freopen("power.out", "w", stdout);
    int ans = 0; read(n); read(k);
    if (k == 1) return !printf("%lld", n);
    F(i, 2, 59) if (!p[i] && i >= k) for(int j = i + i;j <= 59;j += i) p[j] = 1;
    F(i, k, 59){
        if (p[i]) continue;
        int tmp = sqr(n, i);
        ans += tmp - 1;
        F(j, k, i - 1){
            if (j >= tmp) break; if(p[j]) continue;
            ans -= sqr(tmp, j) - 1;
        }
        F(j, k, i - 1) F(w, j + 1, i - 1){
            if (j * w >= 60) break;
            if (j == w || p[j] || p[w]) continue;
            ans += sqr(tmp, j * w) - 1;
        }
    }
    printf("%lld", ans + 1);
    return 0;
}
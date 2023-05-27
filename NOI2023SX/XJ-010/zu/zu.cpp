#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define F(i, a, b) for(int i = a;i <= b;i++)
#define R(i, a, b) for(int i = a;i >= b;i--)
#define Fe(i, u) for(int i = hd[u];i;i = e[i].nxt)
using namespace std;
const int maxn = 15;
void read(int &f){
    char ch = getchar(); int w = 1;
    while (ch < '0' || ch > '9'){
        if (ch == '-') w = -1;
        ch = getchar();
    }
    for(f = 0;ch >= '0' && ch <= '9';f = (f << 3) + (f << 1) + ch - '0', ch = getchar());
    f *= w;
}
int n, m, x[3], y[3], xb, yb, vis[15][15][15][15];
int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
struct node{
    int x, y, st;
};
char a[15][15];
queue<node> q;
int pd(int x, int y){
    return (x - 1 < 1 || a[x - 1][y] == '#') && (x + 1 > n || a[x + 1][y] == '#') && (y - 1 < 1 || a[x][y - 1] == '#') && (y + 1 > m || a[x][y + 1] == '#');
}
int main(){
    freopen("zu.in", "r", stdin);
    freopen("zu.out", "w", stdout);
    int zu, T; read(zu); read(T);
    while (T--){
        memset(a, 0, sizeof(a)); memset(vis, 0, sizeof(vis)); x[1] = x[2] = y[1] = y[2] = 0;
        while (!q.empty()) q.pop();
        read(n); read(m);
        F(i, 1, n) scanf("\n%s", a[i] + 1);
        F(i, 1, n) F(j, 1, m) if (a[i][j] == 'X') xb = i, yb = j;
        else if (a[i][j] == 'O') !x[1] ? (x[1] = i, y[1] = j) : (x[2] = i, y[2] = j);
        if (zu <= 4){
            if (pd(x[1], y[1]) && pd(x[2], y[2])) puts("Black 0");
            else puts("Tie");
        }else if(zu <= 6){
            int t = x[1] == n ? 2 : 1;
            if (xb < x[t] || xb == x[t] && (y[t] - yb > 1 || y[t] - yb < -1))
                printf("Black %d\n", (xb - 1) * 2);
            else if (xb - x[t] < abs(y[t] - yb) - 1) printf("Black %d\n", (xb - 1) * 2);
            else if (y[t] > yb)
                printf("Red %d\n", (yb - 1) * 2 + xb - x[t] + abs(y[t] - yb) + (xb - x[t] == abs(y[t] - yb)));
            else printf("Red %d\n", (m - yb) * 2 + xb - x[t] + abs(y[t] - yb) + (xb - x[t] == abs(y[t] - yb)));
        }else if (zu <= 9){
            if (a[xb + 1][1] == 'O' || a[xb - 1][1] == 'O') { puts("Red 1"); continue; }
            int f = 0; char f1;
            R(i, xb - 1, 1) if (a[i][1] == '#' || a[i][1] == 'O') { f = i; f1 = a[i][1]; break; }
            if (!f) printf("Black %d\n", (xb - 1) * 2);
            else{
                if (pd(x[1], y[1]) && pd(x[2], y[2])) { puts("Black 0"); continue; }
                if (f1 == '#') printf("Red %d\n", (xb - f) * 2 - 1);
                else if ((xb - f) % 2) printf("Red %d\n", xb - f);
                else{
                    int t = f == x[1] ? 2 : 1;
                    if (pd(x[t], y[t])){
                        int x1 = xb, x2 = f, ans = 0;
                        while (x1 != x2){
                            x1--; if (x2 > 1 && a[x2 - 1][1] == '.') x2--;
                            else x2++;
                            ans += 2;
                        }
                        printf("Black %d\n", ans);
                    }else printf("Red %d\n", xb - f + 1);
                }
            }
        }
    }
    return 0;
}
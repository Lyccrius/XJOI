#include<cstdio>
#include<cstring>
using namespace std;
const int P = 1e6 + 4;
int n, m, T, tot;
struct lb{
    int fris, secon;
} s[P], t[P];
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    scanf("%d",&T);
    while(T--){
        memset(s, 0, sizeof s);
        memset(t, 0, sizeof t);
        scanf("%d %d",&n,&m);
        if(n > m) printf("-1\n");
        for(int i = 1;i <= n; i++){
            scanf("%d",&tot);
            if(tot == 1) {
                scanf("%d",&s[i].fris);
            }
            else scanf("%d %d",&s[i].fris,&s[i].secon);
        }
        for(int i = 1;i <= n; i++){
            scanf("%d",&tot);
            if(tot == 1){
                scanf("%d",&t[i].fris);
            }
            else{
                scanf("%d %d",&t[i].fris, &t[i].secon);

            }
        }
        printf("0\n");
    }

    return 0;
}
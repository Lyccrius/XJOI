#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

const int P = 1e5 +3;
struct col{
    int c, th;
} h[P], l[P];
int n, m, t, q;
int main(){
    freopen("paint.in","r",stdin);
    freopen("paint.out","w",stdout);
    scanf("%d",&t);
    while(t--){
        memset(h, 0, sizeof h);
        memset(l, 0, sizeof l);
        scanf("%d %d %d",&n,&m, &q);
        for(int i = 1;i <= q; i++){
            int op, num, co;
            scanf("%d %d %d", &op, &num, &co);
            if(op){
                l[num] = {co, i};
            }
            else{
                h[num] = {co, i};
            }
        }
        for(int i = 1;i <= n; i++){
            for(int j = 1;j <= m; j++){
                if(h[i].th > l[j].th) printf("%d ",h[i].c);
                else printf("%d ",l[j].c);
            }
            printf("\n");
        }
    }

    return 0;
}
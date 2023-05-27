#include<bits/stdc++.h>
using namespace std;
int x[100005][2],y[100005][2];
int n,m,q;
// void out(){
//     for(int i = 1; i <= n; i++){
//         for(int j = 1; j <= m; j++){
//             int ans;
//              if(x[i][1] > y[j][1]) ans = x[i][0];
//              if(x[i][1] <= y[j][1]) ans = y[j][0];
//             printf("%d ",ans);
//         }
//         printf("\n");
//     }
//     printf("\n");
// }
int main(){
	freopen("paint.in","r",stdin);
	freopen("paint.out","w",stdout);
    int T;
	scanf("%d",&T);
    while(T--){
        memset(x,0,sizeof(x));
        memset(y,0,sizeof(y));
        scanf("%d%d%d",&n,&m,&q);
        for(int i = 1; i <= q; i++){
            int o,k,c;
            scanf("%d%d%d",&o,&k,&c);
            if(o == 0) x[k][0] = c,x[k][1] = i;
            else       y[k][0] = c,y[k][1] = i;
            // out();
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                int ans = 0;
                if(x[i][1] > y[j][1]) ans = x[i][0];
                if(x[i][1] <= y[j][1]) ans = y[j][0];
                printf("%d ",ans);
            }
            printf("\n");
        }
    }
	fclose(stdin);
	fclose(stdout);
	return 0;
}

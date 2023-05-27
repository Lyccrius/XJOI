#include<bits/stdc++.h>
using namespace std;
struct point{
    int c;
    int time;
};
point line[100005],col[100005];
int main(){
    freopen("paint.in","r",stdin);
    freopen("paint.out","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--){
        memset(line,0,sizeof line);
        memset(col,0,sizeof col);
        int n,m,q;
        scanf("%d%d%d",&n,&m,&q);
        for(int i=1;i<=q;i++){
            int opt,x,c;
            scanf("%d%d%d",&opt,&x,&c);
            if(opt){
                col[x].c=c;
                col[x].time=i;
            }else{
                line[x].c=c;
                line[x].time=i;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(line[i].time>col[j].time){
                    printf("%d ",line[i].c);
                }else{
                    printf("%d ",col[j].c);
                }
            }
            printf("\n");
        }

    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
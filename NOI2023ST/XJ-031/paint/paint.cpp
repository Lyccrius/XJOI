#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int N=1e5+5;
int mp[N][N];
int main(){
	freopen("paint.in","r",stdin);
	freopen("paint.out","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--){
		memset(mp,0,sizeof(mp));
        int n,m,q;
        scanf("%d%d%d",&n,&m,&q);
        for(int i=1;i<=q;i++){
            int opt,x,c;
            scanf("%d%d%d",&opt,&x,&c);
            if(opt==0){
                for(int i=1;i<=m;i++){
                    mp[x][i]=c;
                }
            }
            else{
                for(int i=1;i<=n;i++){
                    mp[i][x]=c;
                }
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                printf("%d ",mp[i][j]);
            }
            printf("\r");
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

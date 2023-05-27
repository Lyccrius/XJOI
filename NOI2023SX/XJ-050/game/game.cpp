#include <cstdio>
#include <cstring>
using namespace std;
int C;
int n,m;
int S[1100000][5],qwq[1100000],T[1100000][5],qaq[1100000];
int xz[10];
int panA(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=qwq[i];j++){
            for(int k=1;k<=qaq[i];k++){
                if(S[i][j]==T[i][k]){
                    return 0;
                }
            }
        }
    }
    return 1;
}
int panD(){
    for(int i=1;i<=n;i++){
        if(qaq[i]!=qwq[i]){
            return 0;
        }
        for(int j=1;j<=qwq[i];j++){
            if(S[i][j]!=T[i][j]){
                return 0;
            }
        }
    }
    return 1;
}
int dfs_S[110],dfs_T[110];
int dfs_bf[110];
int dfs11(int i){
    int ret=0;
    if(i>n){
        memset(dfs_bf,0,sizeof(dfs_bf));
        for(int j=1;j<=n;j++){
            if(dfs_bf[    T[j][ dfs_T[j] ]    ]!=0){
                return -1;
            }
            dfs_bf[    T[j][ dfs_T[j] ]    ]=1;
            if(T[j][ dfs_T[j] ]==S[j][ dfs_S[j] ]){
                ret++;
            }
        }
        return ret;
    }
    ret=200000000;
    for(int k=1;k<=qaq[i];k++){
        dfs_T[i]=k;
        int temp=dfs11(i+1);
        if(temp>=0&&temp<ret){
            ret=temp;
        }
        dfs_T[i]=0;
    }
    return ret;
}
int dfs10(int i){
    if(i>n){
        memset(dfs_T,0,sizeof(dfs_T));
        int temp=dfs11(1);
        if(temp<0||temp>=200000000){
            return -1;
        }
        return temp;
    }
    int ret=-1;
    for(int j=1;j<=qwq[i];j++){
        dfs_S[i]=j;
        int temp=dfs10(i+1);
        if(temp>=0&&temp>ret){
            ret=temp;
        }
        dfs_S[i]=0;
    }
    return ret;
}
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    scanf("%d",&C);
    for(int i=1;i<=C;i++){
        memset(S,0,sizeof(S));
        memset(qwq,0,sizeof(qwq));
        memset(T,0,sizeof(T));
        memset(qaq,0,sizeof(qaq));
        memset(xz,0,sizeof(xz));
        xz[1]=0;xz[2]=1;xz[3]=1;xz[4]=1;
        scanf("%d%d",&n,&m);
        if(n<3){xz[2]=0;}
        for(int j=1;j<=n;j++){
            scanf("%d",&qwq[j]);
            for(int k=1;k<=qwq[j];k++){
                scanf("%d",&S[j][k]);
            }
            if(qwq[j]==2&&S[j][1]>S[j][2]){
                int temp=S[j][1];
                S[j][1]=S[j][2];
                S[j][2]=temp;
            }
            if(qwq[j]!=1) xz[3]=0;
        }
        for(int j=1;j<=n;j++){
            scanf("%d",&qaq[j]);
            for(int k=1;k<=qaq[j];k++){
                scanf("%d",&T[j][k]);
            }
            if(qaq[j]==2&&T[j][1]>T[j][2]){
                int temp=T[j][1];
                T[j][1]=T[j][2];
                T[j][2]=temp;
            }
            if(j!=n){
                if(qaq[j]!=2||T[j][1]!=j||T[j][2]!=j+1){xz[2]=0;}
            }
            else{
                if(qaq[j]!=2||T[j][2]!=j||T[j][1]!=1){xz[2]=0;}
            }
        }
        xz[1]=panA();
        xz[4]=panD();
        memset(dfs_S,0,sizeof(dfs_S));
        memset(dfs_T,0,sizeof(dfs_T));
        memset(dfs_bf,0,sizeof(dfs_bf));
        printf("%d\n",dfs10(1));
    }
    return 0;
}
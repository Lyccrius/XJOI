#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
const int N=1e4+4;
double x[N],y[N],ky=0;
int n,ki;
bool vis[N];
double ans=1e9;
int cun[N];
int cun2[N];
double d(double x1,double y1,double x2,double y2){
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
void dfs(int k,int tot){
    if(k>n){
        if(tot<ans){
            ans=tot;
            for(int i=1;i<=n;i++){
                cun2[i]=cun[i];
            }
        }
        return;
    }
    else{
        for(int i=1;i<=n;i++){
            if(i==ki||vis[i]){
                continue;
            }
            cun[k]=i;
            vis[i]=true;
            dfs(k+1,tot+d(x[cun[k-1]],y[cun[k-1]],x[i],y[i]));
            vis[i]=false;
        }
    }
}
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%lf%lf",&x[i],&y[i]);
        if(y[i]>ky){
            ky=y[i];
            ki=i;
        }
    }
    cun[1]=ki;
    vis[ki]=true;
    dfs(2,0);
    for(int i=1;i<=n;i++){
        printf("%d ",cun2[i]);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

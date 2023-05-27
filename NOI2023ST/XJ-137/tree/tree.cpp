#include<bits/stdc++.h>
using namespace std;
struct node{
    double x,y;
}a[1010];
int nowp[1010],ans[1010];
bool vis[1010];
int n;
double mind=100000000000005;
double distance(node a,node b){
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
void f(int now,double tot){
    if(tot>=mind){
        return;
    }
    if(now>n){
        mind=tot;
        for(int i=2;i<=n;i++)
            ans[i]=nowp[i];
        return;
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            vis[i]=1;
            nowp[now]=i;
            f(now+1,tot+distance(a[i],a[nowp[now-1]]));
            vis[i]=0;
        }
    }
}
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    scanf("%d",&n);
    int k=1;
    for(int i=1;i<=n;i++){
        scanf("%lf%lf",&a[i].x,&a[i].y);
        if(a[i].y>a[k].y) k=i;
    }
    if(n>=20){
        for(int i=k;i>=1;i--){
            printf("%d ",i);
        }
        for(int i=n;i>k;i--){
            printf("%d ",i);
        }
    }else{
        ans[1]=k,nowp[1]=k,vis[k]=1;
        f(2,0);
        for(int i=1;i<=n;i++){
            printf("%d ",ans[i]);
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
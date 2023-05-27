//30-100tps code by MisakaE
#include<bits/stdc++.h>
using namespace std;
#define llf double
struct pot
{
    llf x,y;
    int id;
    int ta,tb;
};
int n;

llf disf(pot a,pot b){
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
int nx(int t){
    if(t+1<=n)return t+1;
    return 1;
}
int bf(int t){
    if(t-1>0)return t-1;
    return n;
}

pot p[1010];
int ans1[1010],ans2[1010];
bool f[1010];
int main()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        scanf("%lf%lf",&p[i].x,&p[i].y);
    }
    int topp=1;
    llf ky=p[1].y;
    for(int i=2;i<=n;++i)if(p[i].y>ky)topp=i,ky=p[i].y; 
    llf ans_1=0,ans_2=0;
    ans1[1]=topp;
    ans2[1]=topp;
    if(disf(p[topp],p[nx(topp)])<disf(p[topp],p[bf(topp)])){
        int nw=topp;
        for(int i=2;i<=n;++i){
            ans_1+=disf(p[nw],p[nx(nw)]);
            nw=nx(nw);
            ans1[i]=nw;
        }
    }
    else{
        int nw=topp;
        for(int i=2;i<=n;++i){
            ans_1+=disf(p[nw],p[bf(nw)]);
            nw=bf(nw);
            ans1[i]=nw;
        }
    }
    int w=topp;
    for(int i=2;i<=n;++i)
    {
        f[w]=1;
        llf mi=-2;
        int nt=0;
        for(int j=1;j<=n;++j){
            if(w==j||f[j])continue;
            if(mi<0||mi>disf(p[j],p[w]))nt=j,mi=disf(p[j],p[w]);
        }
        w=nt;
        ans2[i]=w;
        ans_2+=mi;
    }
    if(ans_2<ans_1)for(int i=1;i<=n;++i)printf("%d ",ans2[i]);
    else for(int i=1;i<=n;++i)printf("%d ",ans1[i]);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
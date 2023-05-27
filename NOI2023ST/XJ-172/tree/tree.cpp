#include<algorithm>
#include<cstdio>
#include<cmath>
#include<iostream>
#include<vector>
using namespace std;
struct point{
  long double x,y;
}p[1010];
long double calc_dis(point a,point b){
  return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
bool vis[1010];
int s;
long double ans_v=1e18;
vector<int>vc,ans;
int n;
long double dis[1010][1010];
void dfs(int u,long double len){
  vc.emplace_back(u);
  vis[u]=1;
  // bool f=0;
  int idx=-1;
  long double mn=1e18;
  for(int i=1;i<=n;++i){
    if(vis[i])continue;
    // f=1;
    if(dis[u][i]<mn)mn=dis[u][i],idx=i;
    // dfs(i,len+dis[u][i]);
  }
  if(~idx)dfs(idx,len+mn);
  if(/*!f*/!~idx){
    if(ans_v>len){
      ans_v=len;
      ans=vc;
    }
  }
  vc.pop_back();
  vis[u]=0;
}
int main(){
  freopen("tree.in","r",stdin);
  freopen("tree.out","w",stdout);
  scanf("%d",&n);
  long double mx=-1e18;
  for(int i=1;i<=n;++i){
    scanf("%Lf%Lf",&p[i].x,&p[i].y);
    if(p[i].y>mx)s=i,mx=p[i].y;
  }
  for(int i=1;i<=n;++i){
    for(int j=1;j<=n;++j){
      if(i==j)continue;
      dis[i][j]=calc_dis(p[i],p[j]);
    }
  }
  dfs(s,0);
  for(auto i:ans)cout<<i<<' ';
  cout<<endl;
}
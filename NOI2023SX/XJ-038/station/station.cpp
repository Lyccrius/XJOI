#include<algorithm>
#include<cstdio>
#include<vector>
int n,m,x;
struct railway{
  int l,r;
};
std::vector<railway>rw;
std::vector<int>ans;
std::vector<int> fr[5010];
void print(const railway&rw){
  printf("%d,%d\n",rw.l,rw.r);
}
bool vis[2][5010][5010];
void dfs(int i,int rw_nm,bool dr){
  if(vis[dr][i][rw_nm])return;
  vis[dr][i][rw_nm]=1;
  // fprintf(stderr,"%d,%d,%d\n",i,rw_nm,dr);
  if(fr[i].empty())return;
  if(dr){
    if(i==rw[rw_nm].r)
      ans.emplace_back(rw[rw_nm].r);
    for(int j:fr[i])
      if(i!=rw[j].r)dfs(i+1,j,1);
  }else{
    if(i==rw[rw_nm].l)
      ans.emplace_back(rw[rw_nm].l);
    for(int j:fr[i])
      if(i!=rw[j].l)dfs(i-1,j,0);
  }
}
int main(){
  // freopen("in","r",stdin);
  freopen("station.in","r",stdin);
  freopen("station.out","w",stdout);
  scanf("%d%d%d",&n,&m,&x);
  rw.resize(m);
  for(auto&i:rw)
    scanf("%d%d",&i.l,&i.r);
  std::sort(rw.begin(),rw.end(),[](railway&a,railway&b){return a.l==b.l?a.r<b.r:a.l<b.l;});
  rw.resize(m=std::unique(rw.begin(),rw.end(),[](railway&a,railway&b){return a.l==b.l&&a.r==b.r||b.l==b.r;})-rw.begin());
  for(int i=1;i<=n;++i){
    for(int j=0;j<m;++j)
      if(rw[j].l<=i&&i<=rw[j].r)fr[i].emplace_back(j);
  }
  for(int i:fr[x]){
    if(rw[i].l!=x)dfs(x,i,0);
    if(rw[i].r!=x)dfs(x,i,1);
  }
  std::sort(ans.begin(),ans.end());
  ans.resize(std::unique(ans.begin(),ans.end())-ans.begin());
  for(int i:ans)
    printf("%d ",i);
  // int idx=std::lower_bound(rw.begin(),rw.end(),x,[](railway&a,int b){return a.l==b||b==a.r;})-rw.begin();
  // int idx_=idx;
  // while(rw[--idx_].l==x||x==rw[idx_].r);
  // ++idx_;
  // for(int i=0;i<m;++i)
  //   printf("%d,%d\n",rw[i].l,rw[i].r);
  // for(int i=idx_;i<idx;++i)
  //   ans[c++]=(rw[i].l==x?rw[i].r:rw[i].l);
  // std::vector<railway>nw(1,{rw[0].l,rw[0].r});
  // for(int i=1;i<m;++i){
  //   if(rw[i-1].r>=rw[i].l)
  //     nw.back().r=rw[i].r;
  //   else
  //     nw.emplace_back(rw[i]);
  // }
  // for(auto i:nw)
  //   print(i);
  // std::vector<railway>::iterator d;
  // rw.erase(d=std::unique(rw.begin()+idx_,rw.begin()+idx,[](railway&a,railway&b){return a.r=b.r,1;}),rw.begin()+idx);
  // auto nw=*(d-1);
  // rw.erase(d-1);
  // std::vector<std::vector<int>>vc(1,{rw[0].l,rw[0].r});
  // for(int i=1;i<rw.size();++i){
  //   if(rw[i-1].r>=rw[i].l){
  //     rw[i-1].r=rw[i].r,rw.erase(rw.begin()+(i--));
  //     vc.back().emplace_back(rw[i].l);
  //     vc.back().emplace_back(rw[i].r);
  //   }else{
  //     std::sort(vc.back().begin(),vc.back().end());
  //     vc.back().resize(std::unique(vc.back().begin(),vc.back().end())-vc.back().begin());
  //     vc.emplace_back(std::vector<int>{rw[i].l,rw[i].r});
  //   }
  // }
  // std::sort(vc.back().begin(),vc.back().end());
  // vc.back().resize(std::unique(vc.back().begin(),vc.back().end())-vc.back().begin());
  // for(auto i:vc){
  //   for(auto j:i)
  //   puts("");
  // }
  // ed[++c1]=++nm;
  // ed[c1+1]=nm+1;
  // for(int i=0;i<c1;++i){
  //   printf("%d,%d:\n",ed[i],ed[i+1]);
  //   for(int j=ed[i];j<ed[i+1];++j){
  //     print(rw[j]);
  //   }
  //   puts("");
  // }
}
#include<algorithm>
#include<cstdio>
#include<list>
#include<vector>
using ll=long long;
int n,k,m;
std::vector<std::vector<int>>sn;
std::vector<std::vector<ll>>vs;
struct exce{
  int x,nm;
  exce(){}
  exce(int x,int nm):x(x),nm(nm){}
};
std::vector<exce>ex;
ll calc(int u){
  // printf("%d %ld\n",u,vs[u].size());
  // fprintf(stderr,"%d:\n",u);
  // for(int i:vs[u])fprintf(stderr,"%d,",i);
  // fputs("\n",stderr);
  auto tmp=vs[u];
  if(!tmp.empty())
    std::sort(tmp.begin(),tmp.end());
  // fprintf(stderr,"case 0... ");
  ll ret=tmp.empty()?0:*--tmp.end();
  // fputs("ok.\n",stderr);
  for(int v:sn[u]){
    auto tmp_=vs[v].end();
    // fprintf(stderr,"%d:\n",v);
    // for(int i:vs[v])fprintf(stderr,"%d,",i);
    // fputc('\n',stderr);
    if(tmp.size()>1){
      // fprintf(stderr,"case 1... ");
      for(auto tmp1:tmp)
        vs[v].emplace_back(tmp1);
      // fputs("ok.\n",stderr);
      // fprintf(stderr,"case 2... ");
      vs[v].erase(--vs[v].end());
      // fputs("ok.\n",stderr);
    }
    // for(int i:vs[v])fprintf(stderr,"%d,",i);
    // fputc('\n',stderr);
    ret+=calc(v);
    if(tmp.size()>1){
      // fprintf(stderr,"case 3... ");
      for(int i=1;i<tmp.size();++i)
        vs[v].erase(--vs[v].end());
      // fputs("ok.\n",stderr);
    }
    // for(int i:vs[v])fprintf(stderr,"%d,",i);
    // fputc('\n',stderr);
  }
  return ret;
}
int main(){
  // freopen("in","r",stdin);
  freopen("transfer.in","r",stdin);
  freopen("transfer.out","w",stdout);
  int sid;scanf("%d",&sid);
  // switch(sid){
  // case 1 ... 2:
    scanf("%d%d%d",&n,&k,&m);
    sn.resize(n+1),ex.resize(k+1),vs.resize(n+1);
    for(int p,i=2;i<=n;++i)scanf("%d",&p),sn[p].emplace_back(i);
    for(int x,v,i=1;i<=k;++i){
      scanf("%d%lld",&x,&v);
      vs[ex[i].x=x].emplace_back(v);
      ex[i].nm=vs[x].size()-1;
    }
    printf("%lld ",calc(1));
    for(int i=1;i<=m;++i){
      int id;scanf("%d",&id);
      if(id==1){
        int x;ll v;scanf("%d%lld",&x,&v);
        vs[x].emplace_back(v);
        ex.emplace_back(x,vs[x].size()-1);
      }else{
        int nm;scanf("%d",&nm);
        vs[ex[nm].x][ex[nm].nm]=0;
        ex[nm]={0,0};
      }
      printf("%lld ",calc(1));
    }
  // }
}
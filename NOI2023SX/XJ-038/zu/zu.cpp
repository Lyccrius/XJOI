#include<cstdio>
#include<cstdlib>
#include<string>
#include<map>
int id,T;
int n,m;
char pz[11][11];
std::map<std::string,bool>vis;
void swap(char&a,char&b){
  char t=a;
  a=b;
  b=t;
}
int ans[2];
void dfs(int stp,bool rd){
  if(stp>ans[rd])return;
  std::string s;
  for(int i=0;i<n;++i)
    s+=pz[i][0];
  // fprintf(stderr,"%s\n",s.data());
  if(vis[s])return;
  vis[s]=1;
  if(pz[0][0]=='X'){
    if(stp<ans[0])ans[0]=stp;
    //
    return;
  }
  int red=2;
  for(int i=0;i<n;++i){
    if(rd&&pz[i][0]=='O'&&(i>0&&pz[i-1][0]=='X'||i<n-1&&pz[i+1][0]=='X')){
      if(stp<ans[1])ans[1]=stp;
      //
      return;
    }
    if(!rd&&pz[i][0]=='X'&&(i>0&&pz[i-1][0]=='O'||i<n-1&&pz[i+1][0]=='O')){
      if(stp<ans[0])ans[0]=stp;
      //
      return;
    }
    if(pz[i][0]=='O'&&(i<1||pz[i-1][0]=='#')&&(i>n-2||pz[i+1][0]=='#'))
      --red;
  }
  if(!red){
    if(stp<ans[0])ans[0]=stp;
    //
    return;
  }
  for(int i=0;i<n;++i){
    if((rd&&pz[i][0]=='O'||!rd&&pz[i][0]=='X')&&i>0&&pz[i-1][0]=='.'){
      swap(pz[i][0],pz[i-1][0]);
      dfs(stp+1,!rd);
      swap(pz[i][0],pz[i-1][0]);
    }
    if((rd&&pz[i][0]=='O'||!rd&&pz[i][0]=='X')&&i<n-1&&pz[i+1][0]=='.'){
      swap(pz[i][0],pz[i+1][0]);
      dfs(stp+1,!rd);
      swap(pz[i][0],pz[i+1][0]);
    }
  }
}
int main(){
  // freopen("in","r",stdin);
  // freopen("out","w",stdout);
  freopen("zu.in","r",stdin);
  freopen("zu.out","w",stdout);
  scanf("%d%d",&id,&T);
  while(T--){
    scanf("%d%d",&n,&m);
    getchar();
    for(int i=0;i<n;++i){
      for(int j=0;j<m;++j)
        pz[i][j]=getchar();
      getchar();
    }
    if(1<=id&&id<=4){
      int rd=2;
      for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
          if(pz[i][j]=='O'&&(i<1||pz[i-1][j]=='#')&&(i>n-2||pz[i+1][j]=='#')
                          &&(j<1||pz[i][j-1]=='#')&&(j>m-2||pz[i][j+1]=='#'))
            --rd;
        }
      }
      if(!rd)puts("Black 0");
      else puts("Tie");
    }
    if(5<=id&&id<=6){
      int xx,xy,ox,oy;
      for(int i=0;i<n-2;++i){
        for(int j=0;j<m;++j){
          if(pz[i][j]=='X')xx=i,xy=j;
          if(pz[i][j]=='O')ox=i,oy=j;
        }
        // if(xx>dx)
      }
      if(m==1||abs(oy-xy)-1>=xx&&(abs(oy-xy)-1-xx)%2!=0)puts("Tie");
      else printf("Black %d\n",xx);
    }
    if(7<=id&&id<=9){
      if(pz[0][0]=='X'){
        puts("Black 0");
        continue;
      }
      ans[0]=ans[1]=0x7fffffff;
      dfs(1,1);
      if(ans[0]==ans[1])
        puts("Tie");
      else
        printf(ans[1]>ans[0]?"Red %d\n":"Black %d\n",ans[ans[1]>ans[0]]);
      // bool f=1;
      // int red[2]{-1,-1},cnt=0;
      // for(int i=0;i<n;++i){
      //   if()
      //     ++cnt;
      //   else if(pz[i][0]=='O')
      //     red[]
      //   else if(pz[i][0]=='X'&&i>0&&pz[i-1][0]=='#'&&(i>n-2||pz[i+1][0]=='#')){
      //     f=0;
      //     break;
      //   }
      // }
      // if(!f){
      //   fprintf(stderr,"Red 0");
      //   continue;
      // }

    }
    if(10<=id&&id<=20)
      puts("Tie");
  }
}
#include<bits/stdc++.h>
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define pre(i,r,l) for(int i=r;i>=l;i--)
#define ll long long
#define fi first
#define se second
#define pir pair<int,int>
using namespace std;
int T,n,m,id;
const int N=110;
pir f[2][110][110][110];
bool vis[2][110][110][110];
int du[2][110][110][110],s1,s2,t,rt[N];
char mp[N][N];
int dx[]={0,0,-1,1},dy[]={1,-1,0,0};
pir find(int x){
    return make_pair((x-1)/m+1,(x-1)%m+1);
}
int m_p(int x,int y){
    return m*(x-1)+y;
}
bool chk(pir now){
    //pir now=find(x);
    if(!now.fi||!now.se||now.fi>n||now.se>m)return 1;
    if(mp[now.fi][now.se]=='#')return 1;
    return 0;
}
int g(int x){
    return (find(x).fi^find(x).se);
}
/*bool use(int o,int x,int y,int z){
    if((g(x)^g(y)^g(z)^g(t)^g(s1)^g(s2)^o)&1)return 1;
    return 0;
}*/
bool chk1(int o,int x,int y,int z){
    if((rt[x]^rt[y]^rt[z]^rt[s1]^rt[s2]^rt[t]^o)&1)return 1;
   // if((x^t^y^s1^z^s2^o)&1)return 1; 
  // if((g(x)^g(y)^g(z)^g(t)^g(s1)^g(s2)^o)&1)return 1;
    return chk(find(x))||chk(find(y))||chk(find(z))||y==z;
}
int check1(int x){
    pir now=find(x);int cnt=0;
    rep(i,0,2){
        if(!chk(make_pair(now.fi+dx[i],now.se+dy[i])))cnt++;
    }
    return cnt;
}
int check2(int x,int y){
    pir now=find(x);int cnt=0;
    rep(i,0,3){
        if(m_p(now.fi+dx[i],now.se+dy[i])==y)continue;
        if(!chk(make_pair(now.fi+dx[i],now.se+dy[i])))cnt++;
    }
    return cnt;
}
int chk2(int o,int x,int y,int z){
    if(find(x).fi==1&&!o)return 1;
    if(x==y||x==z)return 1;
    if(o)du[o][x][y][z]=check1(x);
    else  du[o][x][y][z] =check2(y,z)+check2(z,y);
    return du[o][x][y][z]==0;
}
struct node{
    int o,x,y,z;
}q[N*N*N*2];
int l=1,r;
void init(){
    memset(f,0,sizeof(f));
    memset(vis,0,sizeof(vis));
    memset(du,0,sizeof(du));
    l=1,r=0;s1=s2=t=0;
}
void solve(){
    cin>>n>>m;init();
    rep(i,1,n)scanf("%s",mp[i]+1);
    rep(i,1,n)rep(j,1,m){
        if(mp[i][j]=='O'){
            if(!s1)s1=m_p(i,j);
            else s2=m_p(i,j);
        }
        if(mp[i][j]=='X')t=m_p(i,j);
    }
    rep(i,1,n*m)rt[i]=g(i);
    rep(o,0,1)
    rep(i,1,n*m){
        rep(j,1,n*m)
            rep(k,1,n*m){
               // if(use(o,i,j,k))continue;
                if(chk1(o,i,j,k))continue;
                if(chk2(o,i,j,k)){
                    f[o][i][j][k]=make_pair(0,0);
                    vis[o][i][j][k]=1;
                    q[++r]=(node){o,i,j,k};
                }
            }
    }
  //  cout<<du[1][8][4][6]<<endl;
    while(l<=r){
        node x=q[l++];pir ret=f[x.o][x.x][x.y][x.z];
        if(x.o==0&&x.x==t&&x.y==s1&&x.z==s2)break;
        if(!x.o){
            pir now=find(x.x);
            rep(i,0,2)
                if(!chk(make_pair(now.fi-dx[i],now.se-dy[i]))){
                    int nx=m_p(now.fi-dx[i],now.se-dy[i]);
                 //   if(x.y>x.z)swap(x.y,x.z);
                    if(vis[x.o^1][nx][x.y][x.z])continue;
                    if(ret.fi){
                        if(!--du[x.o^1][nx][x.y][x.z]){
                            vis[x.o^1][nx][x.y][x.z]=1;
                            f[x.o^1][nx][x.y][x.z]=make_pair(0,ret.se+1);
                            q[++r]=(node){x.o^1,nx,x.y,x.z};
                        }
                    }
                    else {
                        vis[x.o^1][nx][x.y][x.z]=1;
                        f[x.o^1][nx][x.y][x.z]=make_pair(1,ret.se+1);
                        q[++r]=(node){x.o^1,nx,x.y,x.z};
                    }
                }
        }
        else{
            pir now=find(x.y);
            rep(i,0,3)
                if(!chk(make_pair(now.fi+dx[i],now.se+dy[i]))){
                    int ny=m_p(now.fi+dx[i],now.se+dy[i]);
                    if(ny==x.z)continue;
                    //if(ny>x.z)swap(ny,x.z);assert(ny<x.z);
                    if(vis[x.o^1][x.x][ny][x.z])continue;
                    if(ret.fi){
                        if(!--du[x.o^1][x.x][ny][x.z]){
                            vis[x.o^1][x.x][ny][x.z]=1;
                            f[x.o^1][x.x][ny][x.z]=make_pair(0,ret.se+1);
                            q[++r]=(node){x.o^1,x.x,ny,x.z};
                        }
                    }
                    else {
                        vis[x.o^1][x.x][ny][x.z]=1;
                        f[x.o^1][x.x][ny][x.z]=make_pair(1,ret.se+1);
                        q[++r]=(node){x.o^1,x.x,ny,x.z};
                    }
                }
            now=find(x.z);
            rep(i,0,3)
                if(!chk(make_pair(now.fi+dx[i],now.se+dy[i]))){
                    int nz=m_p(now.fi+dx[i],now.se+dy[i]);
                    if(nz==x.y)continue;
                    if(vis[x.o^1][x.x][x.y][nz])continue;
                    if(ret.fi){
                        if(!--du[x.o^1][x.x][x.y][nz]){
                            vis[x.o^1][x.x][x.y][nz]=1;
                            f[x.o^1][x.x][x.y][nz]=make_pair(0,ret.se+1);
                            q[++r]=(node){x.o^1,x.x,x.y,nz};
                        }
                    }
                    else {
                        vis[x.o^1][x.x][x.y][nz]=1;
                        f[x.o^1][x.x][x.y][nz]=make_pair(1,ret.se+1);
                        q[++r]=(node){x.o^1,x.x,x.y,nz};
                    }
                }
        }
    }
   // cout<<vis[0][8][4][6]<<endl;
   // cout<<find(5).fi<<" "<<find(5).se<<endl;
  // cout<<du[0][8][4][6]<<endl;
  /*  rep(o,0,1)
    rep(i,1,n*m)
        rep(j,1,n*m)
            rep(k,1,n*m)
                if(i==8&&j==4&&k==5||i==5&&j==4&&k==5){
                    cout<<o<<" "<<i<<" "<<j<<" "<<k<<" ";
                    cout<<du[o][i][j][k]<<" ";
                    if(f[o][i][j][k].fi)printf("Red %d\n",f[o][i][j][k].se);
                    else printf("Black %d\n",f[o][i][j][k].se);
                }*/
   // cout<<du[0][t][s1][s2]<<endl;
    if(!vis[0][t][s1][s2])puts("Tie");
    else{
        if(f[0][t][s1][s2].fi)printf("Red %d\n",f[0][t][s1][s2].se);
        else printf("Black %d\n",f[0][t][s1][s2].se);
    }
}
int main(){
    freopen("zu.in","r",stdin);
    freopen("zu.out","w",stdout);
    cin>>id>>T;
    while(T--)solve();
}
/*pku#1204*01@
3 1
3 3
#.#
O.O
.X.

*/
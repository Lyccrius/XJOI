//20-45pts code by Curlin
#include<bits/stdc++.h>
using namespace std;
int id,t;
char mp[15][15];
int n,m;
int blkx,blky,red1x,red1y,red2x,red2y;
bool vis[15][15];
int q[1000010][7];
int dx[4]={0,-1,0,1},dy[4]={1,0,-1,0};
void start(){
    memset(mp,0,sizeof mp);
    memset(vis,0,sizeof vis);
    memset(q,0,sizeof q);
    red1x=red1y=red2x=red2y=0;
    n=m=0;
}
bool check79(int rx){
    int flag=1;
    dx[0]=1,dx[1]=-1;
    for(int i=0;i<2;i++){
        int tx=rx+dx[i];
        if(mp[tx][1]!='#'&&mp[tx][1]!='O'&&tx>0&&tx<=n) flag=0;
    }
    if(flag) return 0;
    else return 1;
}
void mian(){
    start();
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>mp[i][j];
            if(mp[i][j]=='X') blkx=i,blky=j;
            else if(mp[i][j]=='O') {
                if(red1x==0&&red1y==0) red1x=i,red1y=j;
                else red2x=i;red2y=j;
            }
        }
    }
    if(id>=1&&id<=4){
        int flag=1;
        for(int i=0;i<4;i++){
            int tx=red1x+dx[i],ty=red1y+dy[i];
            if(mp[tx][ty]!='#'&&tx>0&&tx<=n&&ty>0&&ty<=m) flag=0;
        }
        for(int i=0;i<4;i++){
            int tx=red2x+dx[i],ty=red2y+dy[i];
            if(mp[tx][ty]!='#'&&tx>0&&tx<=n&&ty>0&&ty<=m) flag=0;
        }
        if(flag) cout<<"Black 0\n";
        else cout<<"Tie\n";
    }
    else if(id>=7&&id<=9){
        if(!check79(red1x)&&!check79(red2x)){
            cout<<"Black 0\n";
            return;
        }
        if(mp[blkx-1][1]=='#'){
            cout<<"Red 1\n";
            return;
        }
        if(red1x>red2x) swap(red1x,red2x);
        int cnt=0;
        if(abs(red2x-blkx)==1||abs(red1x-blkx)==1) cout<<"Red 1\n";
        else if(red1x>blkx){
            int kk=blkx;
            while(mp[kk][1]!='#'&&kk) kk--;
            if(kk) cout<<"Black "<<blkx*2<<endl;
            else cout<<"Red "<<(blkx-kk)*2-1<<endl;
        }
        else if(red1x<blkx&&red2x>blkx){
            int kk=blkx;
            while(mp[kk][1]!='#'&&kk) kk--;
            if(!kk){
                if(kk>red1x) cout<<"Red "<<(blkx-kk)*2-1<<endl;
                else{
                    if(!check79(red2x)){
                        if((blkx-red1x)%2){
                            cout<<"Red "<<blkx-red1x<<endl;
                        }
                        else{
                            cout<<"Black "<<blkx-red1x<<endl;
                        }
                    }
                    else{
                        if((blkx-red1x)%2){
                            cout<<"Red "<<blkx-red1x<<endl;
                        }
                        else{
                            cout<<"Red "<<blkx-red1x+1<<endl;
                        }
                    }
                }
            } 
            else{
                if(!check79(red2x)){
                    if((blkx-red1x)%2){
                        cout<<"Red "<<blkx-red1x<<endl;
                    }
                    else{
                        cout<<"Black "<<blkx-red1x<<endl;
                    }
                }
                else{
                    if(!check79(red2x)){
                        if((blkx-red1x)%2){
                            cout<<"Red "<<blkx-red1x<<endl;
                        }
                        else{
                            cout<<"Black "<<blkx-red1x<<endl;
                        }
                    }
                    else{
                        if((blkx-red1x)%2){
                            cout<<"Red "<<blkx-red1x<<endl;
                        }
                        else{
                            cout<<"Red "<<blkx-red1x+1<<endl;
                        }
                    }
                }
            }
        }
        else{
            int kk=blkx;
            while(mp[kk][1]!='#'&&kk) kk--;
            if(!kk){
                if(red1x<kk&&red2x<kk) cout<<"Red "<<(blkx-kk)*2-1;
                else if(red1x<kk&&red2x>kk){
                    if(!check79(red1x)){
                        if((blkx-red2x)%2){
                            cout<<"Red "<<blkx-red2x<<endl;
                        }
                        else{
                            cout<<"Black "<<blkx-red2x<<endl;
                        }
                    }
                    else{
                        if((blkx-red2x)%2){
                            cout<<"Red "<<blkx-red2x<<endl;
                        }
                        else{
                            cout<<"Red "<<blkx-red2x+1<<endl;
                        }
                    }
                }
                else{
                    if((blkx-red2x)%2){
                        cout<<"Red "<<blkx-red2x<<endl;
                    }
                    else if(!check79(red1x)){
                        cout<<"Black "<<blkx-red2x<<endl;
                    }
                    else cout<<"Red "<<blkx-red2x+1<<endl;
                }
            }
        }
    }
    else if(id==5||id==6){
        if(red1x==n){
            swap(red1x,red2x);
            swap(red1y,red2y);
        }
        if(red1x==blkx&&(red1y==blky-1||red1y==blky+1)){
            cout<<"Red 1\n";
        }
        else if(red1x==blkx&&abs(red1y-blky)>1){
            int tt=blkx-1;
            cout<<"Black "<<tt<<endl;
        }
        else if(red1x>blkx){
            int tt=blkx-1;
            cout<<"Black "<<tt<<endl;
        }
        else if(red1x<blkx){
            int disx=abs(red1x-blkx),disy=abs(red1y-blky);
            if(disy>disx+1){
                int tt=blkx-1;
                cout<<"Black "<<tt<<endl;
            }
            else if((disx+disy)%2==0){
                cout<<"Tie\n";
            }
            else{
                int tt=max(blky-1,m-blky);
                int rop=disx+disy+2*tt;
                cout<<"Red "<<rop<<endl;
            }
        }
    }
    else if(id>=10&&id<=13){
        cout<<"Tie\n";
    }
    else{
        cout<<"Tie\n";
    }
}
int main(){
    freopen("zu.in","r",stdin);
    freopen("zu.out","w",stdout);
    cin>>id>>t;
    for(int i=1;i<=t;i++) mian();
    return 0;
}
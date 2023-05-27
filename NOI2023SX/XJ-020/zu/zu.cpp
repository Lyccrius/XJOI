#include<bits/stdc++.h>
using namespace std;
int T,n,m,id,path[12][12],vis;
char a;

queue<int> Q;
struct sde{
    int x,y;
}side[3];
int main(){
    freopen("zu.in","r",stdin);
    freopen("zu.out","w",stdout);
    cin>>id>>T;
    for(int k=1;k<=T;k++){
        cin>>n>>m;
        memset(path,0,sizeof path);
        int b=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>a;
                
                if(a=='.'){
                    path[i][j]=1;
                }else if(a=='#'){
                    path[i][j]=0;
                }else if(a=='O'){
                    path[i][j]=2;
                    side[b].x=i,side[b++].y=j;
                }else{
                    path[i][j]=3;
                }
            }
        }
        int x1=side[1].x ,y1=side[1].y,x2=side[2].x,y2=side[2].y;
        if(!path[x1-1][y1]&&!path[x1+1][y1]&&!path[x1][y1+1]&&!path[x1][y1-1]&&!path[x2-1][y2]&&!path[x2+1][y2]&&!path[x2][y2+1]&&!path[x2][y2-1]){
            cout<<"Black 0"<<endl;
        }else{
            cout<<"Tie"<<endl;
        }
    }


    return 0;
}
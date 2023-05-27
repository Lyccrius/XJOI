#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+10;
int id,T;
int m,n;
int a[20][20];
int r[3][3];
int bx,by;
int dx[4]={-1,0,0,1};
int dy[4]={0,-1,1,0};
int b[20][20];
void find(int x,int y){
    for(int i=0;i<3;i++){
        int x1=x+dx[i];
        int y1=y+dy[i];
        if(x1>=1&&x1<=n&&y1>=1&&y1<=m&&a[x1][y1]==0){
            b[x1][y1]=min(b[x1][y1],b[x][y]+1);
            find(x1,y1);
        }
    }
    return;
}
int main(){
    freopen("zu.in","r",stdin);
    freopen("zu.out","w",stdout);
    cin>>id>>T;
    while(T--){
        cin>>n>>m;
        char c;
        int cnt=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>c;
                if(c=='.'){
                    a[i][j]=0;
                }
                else if(c=='#'){
                    a[i][j]=1;
                }
                else if(c=='X'){
                    bx=i;
                    by=j;
                    a[i][j]=1;
                }
                else if(c=='O'){
                    r[cnt][1]=i;
                    r[cnt][2]=j;
                    cnt++;
                    a[i][j]=1;
                }
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                b[i][j]=MAXN;
            }
        }
        int flag=0;
        for(int i=1;i<cnt;i++){
            int x=r[cnt][1];
            int y=r[cnt][2];
            for(int j=0;j<4;j++){
                int x1=x+dx[i];
                int y1=y+dy[i];
                if(x1<1||x1>n||y1<1||y1>m){
                    flag+=1;
                }
                else if(a[x1][y1]){
                    if(x1==bx&&y1==by){
                        flag=MAXN;
                        break;
                    }
                    flag+=1;
                }
            }
        }
        int flag1=0;
        for(int i=0;i<3;i++){
            int x1=bx+dx[i];
            int y1=by+dy[i];
            if(x1<1||x1>n||y1<1||y1>m||a[x1][y1]){
                flag1+=1;
            }
        }
        if(flag==8){
            cout<<"Black 0"<<endl;
            continue;
        }
        else if(flag==MAXN){
            cout<<"Red 1"<<endl;
            continue;
        }
        else if(flag<8&&id>=1&&id<=4){
            cout<<"Tie"<<endl;
            continue;
        }
        if(flag1==3){
            cout<<"Red 0"<<endl;
            continue;
        }
    }
    return 0;
}
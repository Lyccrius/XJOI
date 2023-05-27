#include<iostream>
#include<cstdio>
using namespace std;
const int maxn=20;
int s,T,n,m;
char a[maxn][maxn];
int xi[4]={0,0,1,-1};
int yi[4]={1,-1,0,0};
void work1(){
    int flg=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i][j]!='O') continue;
            for(int t=0;t<4;t++){
                int xx=i+xi[t];
                int yy=j+yi[t];
                if((xx==0)||(xx==(n+1))) continue;
                if((yy==0)||(yy==(m+1))) continue;
                if((a[xx][yy]!='#')&&(a[xx][yy]!='O')){
                    flg=1;
                    break;
                }
            }
        }
    }
    if(flg) cout<<"Tie"<<endl;
    else cout<<"Black 0"<<endl;
}
void work2(){
    int flg=0;
    int hg=n+1,ho=n+1,hx=n+1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i][j]=='#') hg=min(hg,i);
            if(a[i][j]=='X') hx=min(hx,i);
            if(a[i][j]!='O') continue;
            ho=min(ho,i);
            for(int t=0;t<4;t++){
                int xx=i+xi[t];
                int yy=j+yi[t];
                if((xx==0)||(xx==(n+1))) continue;
                if((yy==0)||(yy==(m+1))) continue;
                if((a[xx][yy]!='#')&&(a[xx][yy]!='O')){
                    flg=1;
                    break;
                }
            }
        }
    }
    if(flg==0) cout<<"Black 0"<<endl;
    else if((hx<hg)&&(hx<ho)) cout<<"Black "<<(hx-1)*2<<endl;
    else if(hx>=4)
         if(a[hx-2][1]=='O')
         if(a[hx-3][1]=='O')
         if((a[hx-4][1]=='#')||(hx==4)) cout<<"Black 2"<<endl;
    else if(a[hx+1][1]=='O') cout<<"Red 1"<<endl;
    else{
        cout<<"Red "<<endl;
        int anss=100;
        int ttt=hx-1;
        while(ttt>=1){
            if(a[ttt][1]=='#'){
                cout<<2*(hx-ttt-1)+1<<endl;
                break;
            }
            if(a[ttt][1]=='O'){
                if((hx-ttt)%2==0) cout<<hx-ttt+1;
                else cout<<hx-ttt;
                cout<<endl;
                break;
            }
            ttt--;
        }
    }
}
int main(void){
    freopen("zu.in","r",stdin);
    freopen("zu.out","w",stdout);
    cin>>s>>T;
    for(int t=1;t<=T;t++){
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            cin>>(a[i]+1);
        }
        if(s<=4) work1();
        else if((s>=7)&&(s<=9)) work2();
        else cout<<"Tie"<<endl;
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
const int x=1010;
int m,n,T;
int s[x],t[x],a[x][x],b[x][x];
int c[x],f[x];
int panduan(){
    f[1]=b[1][1];
    int flag=0,x;
    for(int i=2;i<=n;i++){
        for(int j=1;j<=t[i];j++){
            flag=0;
            for(int k=1;k<=i-1;k++){
                if(b[i][j]==f[k]){
                    flag=1;
                }
            }
            if(flag==1){
                continue;
            }
            else {
                f[i]=b[i][j];
            }
            if(j==t[i]&&flag==1){
                return -1;
            }
        }
    }
    return 0;
}
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>T;
    for(int o=1;o<=T;o++){
        memset(s,0,sizeof(s));
        memset(a,0,sizeof(a));
        memset(t,0,sizeof(t));
        memset(b,0,sizeof(b));
        memset(f,0,sizeof(f));
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            cin>>s[i];
            for(int j=1;j<=s[i];j++){
                cin>>a[i][j];
            }
        }
        for(int i=1;i<=n;i++){
            cin>>t[i];
            for(int j=1;j<=t[i];j++){
                cin>>b[i][j];
            }
        }
        if(panduan()==-1){
            cout<<"-1"<<endl;
            continue;
        }
        else cout<<"0"<<endl;
        for(int i=1;i<=n;i++){
            cout<<f[i]<<" ";
        }cout<<endl;
    }
    return 0;
    fclose(stdin);
    fclose(stdout);
}
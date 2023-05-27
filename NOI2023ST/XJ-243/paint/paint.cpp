#include<bits/stdc++.h>
using namespace std;
const int N=10010;
int T,n,m,q,opt,x,c;
int a[N][N];
int main(){
    freopen("paint.in","r",stdin);
    freopen("paint.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n>>m>>q;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                a[i][j]=0;
            }
        }
        for(int i=1;i<=q;i++){
            cin>>opt>>x>>c;
            if(opt){
                for(int j=1;j<=n;j++){
                    a[j][x]=c;
                }
            }
            else{
                for(int j=1;j<=m;j++){
                    a[x][j]=c;
                }
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cout<<a[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int a[10005][10005];
int main(){
    freopen("paint.in","r",stdin);
    freopen("paint.out","w",stdout);
    int T,n,m,q,out,x,c;
    cin>>T;
    while(T--){
        cin>>n>>m>>q;
        for(int i=1;i<=q;i++){
            cin>>out>>x>>c;
            if(out==0){
                for(int j=1;j<=n;j++){
                    a[x][j]=c;
                }
            }else if(out==1){
                for(int j=1;j<=n;j++){
                    a[j][x]=c;
                }
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cout<<a[i][j]<<" ";
                a[i][j]=0;
            }
            cout<<endl;
        }
    }
    return 0;
}
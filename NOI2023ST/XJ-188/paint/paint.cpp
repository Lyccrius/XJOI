#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("paint.in","r",stdin);
    freopen("paint.out","w",stdout);
    long long T,n,m,q,opt,x,c,a[1010][1010]={0};
    cin>>T;
    while(T--){
        memset(a,0,sizeof(a));
        cin>>n>>m>>q;
        for(long long i=1;i<=q;i++){
            cin>>opt>>x>>c;
            if(opt==0){
               for(long long j=1;j<=m;j++)
                   a[x][j]=c; 
            }
            if(opt==1){
                for(long long j=1;j<=n;j++)
                    a[j][x]=c;
            }
        }
        for(long long i=1;i<=n;i++){
            for(long long j=1;j<=m;j++)
                cout<<a[i][j]<<' ';
            cout<<endl;
        }
    }
    return 0;
}
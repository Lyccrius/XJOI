#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4;
long long c[maxn][maxn]={};
long long t,n,m,q,opt,x,c2=0;
int main(){
    freopen("paint.in","r",stdin);
    freopen("paint.out","w",stdout);
    memset(c,0,sizeof(c));
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n>>m>>q;
        for(int j=0;j<q;j++){
            cin>>opt>>x>>c2;
            if(opt==0){
                for(int x1=1;x1<=n;x1++){
                    c[x][x1]=c2;
                }
            }
            if(opt==1){
                for(int x1=1;x1<=m;x1++){
                    c[x1][x]=c2;
                }
            }
        }
        for(int k=1;k<=n;k++){
            for(int l=1;l<=m;l++){
                cout<<c[k][l]<<" ";
            }
            cout<<endl;
        }
        memset(c,0,sizeof(c));
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
    
}

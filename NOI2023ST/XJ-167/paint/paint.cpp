#include<bits/stdc++.h>
using namespace std;

int n,m,q,cnt;
long long int tu[10000][10000],tx[100001],o[100001],c[100001];
int main(){
    freopen("./paint.in","r",stdin);
    freopen("./paint.out","w",stdout);
    cin>>cnt;
    for(int p=0;p<cnt;p++){
        cin>>n>>m>>q;
        for(int i=1;i<=n;i++){
            for(int j=0;j<=m;j++){
                tu[i][j]=0;
                }
            }
        for(int i=1;i<=q;i++){
        cin>>o[i]>>tx[i]>>c[i];
        if(o[i]==1){
            for(int k=1;k<=m;k++){
                tu[k][tx[i]]=c[i];
                }
            }
        else if(!o[i]){
            for(int l=1;l<=n;l++){
                tu[tx[i]][l]=c[i];
                }
            }
    }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cout<<tu[i][j]<<" ";
                }
            cout<<endl;
            }
    }
    return 0;
}
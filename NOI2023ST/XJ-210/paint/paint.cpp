#include<bits/stdc++.h>
using namespace std;

int T;
int n,m,q;
int opt,x,c;
int pai[10010][10010];

int main(){
    freopen("paint.in","r",stdin);
    freopen("paint.out","w",stdout);
    cin>>T;
    for(int k=1;k<=T;k++){
        cin>>n>>m>>q;
        for(int i=1;i<=q;i++){
            cin>>opt>>x>>c;
            if(opt==0){
                for(int j=1;j<=m;j++){
                    pai[x][j]=c;
                }
            }
            else if(opt==1){
                for(int j=1;j<=n;j++){
                    pai[j][x]=c;
                }
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++){
                cout<<pai[i][j]<<" ";
                pai[i][j]=0;
            }
            cout<<endl;
        }

    }
}
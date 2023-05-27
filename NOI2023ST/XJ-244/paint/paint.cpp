#include<bits/stdc++.h>
using namespace std;
int n,m,q,t;
int opt[10005],x[10005],c[10005],f[10005][10005];
int main(){
    freopen("paint.in","r",stdin);
    freopen("paint.out","w",stdout);
    cin>>t;
	for(int i=1;i<=t;i++){
        cin>>n>>m>>q;
        for(int j=1;j<=q;j++){
            cin>>opt[j]>>x[j]>>c[j];
            if(opt[j]!=1){
                for(int k=1;k<=m;k++){
                        f[x[j]][k]=c[j];
                    }
                }
            else{
               for(int k=1;k<=n;k++){
                    f[k][x[j]]=c[j];
                }
            }
        }
        for(int l=1;l<=n;l++){
            for(int a=1;a<=m;a++){
                cout<<f[l][a]<<" ";
                f[l][a]==0;
            }
            cout<<endl;

        }

	}
	return 0;

}

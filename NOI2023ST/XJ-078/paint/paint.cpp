#include <bits/stdc++.h>
using namespace std;
int t,n,m,q,a[10005][10005];
int main(){
	freopen("paint.in","r",stdin);
	freopen("paint.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n>>m>>q;
        memset(a,0,sizeof(a));
        for(int i=1;i<=q;i++){
            int opt,x,c;
            cin>>opt>>x>>c;
            if(opt==0){
                for(int j=1;j<=m;j++){
                    a[x][j]=c;
                }
            }else{
                for(int j=1;j<=n;j++){
                    a[j][x]=c;
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
    fclose(stdin);
    fclose(stdout);
    return 0;
}

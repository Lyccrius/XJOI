#include <bits/stdc++.h>
using namespace std;
  int b[1010][1010];
void paint(int n,int m,int q){
    int x[q+1],y[q+1],z[q+1];
    for(int i=1;i<=q;++i){
        cin>>x[i]>>y[i]>>z[i];}

        memset(b,0,sizeof(b));
        for(int a=1;a<=q;++a){
            if(x[a]==0){
                for(int j=1;j<=m;++j) b[y[a]][j]=z[a];
            }
            if(x[a]==1){
                for(int j=1;j<=n;++j) b[j][y[a]]=z[a];
            }
        }
return;
}
int main(){
    freopen("paint.in","r",stdin);
    freopen("paint.out","w",stdout);
    int k;
    cin>>k;
    for(int i=1;i<=k;++i){
    int n,m,q;
    cin>>n>>m>>q;
    paint(n,m,q);
    for(int d=1;d<=n;++d){
        for(int e=1;e<=m;++e){
            if(e==m){
                cout<<b[d][e];
            }

           else cout<<b[d][e]<<" ";
        }
        if(d==n&&i==k)break;
        cout<<endl;
    }
    }
    
     fclose(stdin);
     fclose(stdout);
    }
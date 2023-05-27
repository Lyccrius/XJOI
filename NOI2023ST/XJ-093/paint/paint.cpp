#include<bits/stdc++.h>
using namespace std;
int T,n,m,q;
int a[10020][10020];
int main(){
    freopen("paint.in","r",stdin);
    freopen("paint.out","w",stdout);
    cin>>T;
    while(T--){
       memset(a,0,sizeof(a));
        cin>>n>>m>>q;
        for(int i=1;i<=q;i++){
            int op,x,c;
            cin>>op>>x>>c;
            if(op==0){
            for(int j=1;j<=m;j++){
                a[x][j]=c;
            }
           }
             if(op==1){
               for(int i=1;i<=n;i++){
                   a[i][x]=c;
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

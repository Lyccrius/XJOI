#include<bits/stdc++.h>
using namespace std;
const int MAX=3e4;
int t,n,m,q,xi,ci;
bool opti;
int a[(MAX+5)*(MAX+5)];
int main(){
    freopen("paint.in","r",stdin);
    freopen("paint.out","w",stdout);
    cin>>t;
    while(t--){
        memset(a,0,sizeof(a));
        cin>>n>>m>>q;
        while(q--){
            cin>>opti>>xi>>ci;
            if(opti){
                for(int i=xi;i<=n*m;i+=m){
                    a[i]=ci;
                }
            }else{
                for(int i=(xi-1)*m+1;i<=xi*m;++i){
                    a[i]=ci;
                }
            }
        }
        for(int i=1;i<=n;++i){
            for(int j=1;j<=m;++j){
                cout<<a[(i-1)*m+j]<<' ';
            }
            cout<<endl;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
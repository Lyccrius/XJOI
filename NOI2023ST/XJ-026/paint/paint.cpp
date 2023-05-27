#include<bits/stdc++.h>
using namespace std;
struct node{
    int opt,x;
    long long int c;
}t[100000];
int T,n,m,q;
int main(){
   freopen("paint.in","r",stdin);
   freopen("paint.out","w",stdout);
   cin>>T;
   while(T--){
     memset(t,0,sizeof(t));
     cin>>n>>m>>q;
     int di=q;
     int i=1;
     while(di--){
        cin>>t[i].opt>>t[i].x>>t[i].c;
        i++;
     }
     for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            for(int k=q;k>=1;k--){
                if((t[k].opt==0&&t[k].x==i)||(t[k].opt==1&&t[k].x==j)){
                    cout<<t[k].c<<" ";
                    break;
                }
                if(k==1)
                cout<<"0"<<" ";
            }

        }
        cout<<endl;
     }
   }
   return 0;
}

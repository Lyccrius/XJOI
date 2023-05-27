#include<bits/stdc++.h>
using namespace std;
const int N=100010;
int T,n,m,q;
int cx[N],cy[N],xmax,ymax,nx[N],ny[N];
int main(){
    freopen("paint.in","r",stdin);
    freopen("paint.out","w",stdout);
    cin>>T;
    for(int aa=1;aa<=T;aa++){
        cin>>n>>m>>q;
        memset(cx,0,sizeof cx);
        memset(cy,0,sizeof cy);
        memset(nx,0,sizeof nx);
        memset(ny,0,sizeof ny);
        xmax=0;
        ymax=0;
        for(int i=1,opt,x,c;i<=q;i++){
            cin>>opt>>x>>c;
            if(opt==0){
                cx[x]=c;
                nx[x]=ymax+1;
                if(nx[x]>xmax) xmax=nx[x];
            }
            else{
                cy[x]=c;
                ny[x]=xmax+1;
                if(ny[x]>ymax) ymax=ny[x];
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<m;j++){
                if(nx[i]>ny[j]) cout<<cx[i]<<" ";
                else cout<<cy[j]<<" ";
            }
            if(nx[i]>ny[m]) cout<<cx[i];
            else cout<<cy[m];
            cout<<endl;
        }
    }
    return 0;
}
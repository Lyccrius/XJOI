#include<bits/stdc++.h>
using namespace std;
const int M=102410;
long long n,m,q,t,opt;
long long x,c,cmp;
long long hang[M],lie[M],cntl[M],cnth[M];
void print(){
    if(cmp==q){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cout<<lie[j]<<" ";
            }cout<<endl;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(cnth[i]>cntl[j]) cout<<hang[i]<<" ";
            else cout<<lie[j]<<" ";
        }
        cout<<endl;
    }
}
int main(){
    freopen("paint.in","r",stdin);
    freopen("paint.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++){
        memset(hang,0,sizeof(hang));
        memset(lie,0,sizeof(lie));
        memset(cnth,0,sizeof(cnth));
        memset(cntl,0,sizeof(cntl));
        cin>>n>>m>>q;
        for(int j=1;j<=q;j++){
            cin>>opt>>x>>c;
            if(opt==1){
                lie[x]=c;
                cntl[x]=j;
                cmp++;
            }
            else{
                hang[x]=c;
                cnth[x]=j;
            }
        }
        print();
    }
    return 0;
}
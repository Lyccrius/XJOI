#include<iostream>
#include<stdio.h>
#include<cmath>
using namespace std;
int tt,n,m,s[1000050][10],t[1000050][10],a,l=0;
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    scanf("%d %d",&tt);
    for(int ii=1;ii<=tt;ii++){
        scanf("%d %d",&n,&m);
        for(int i=1;i<=n;i++){
            cin>>a;
            cin>>s[i][1];
            if(a==2)cin>>s[i][2];
            if(s[i][1]<s[i][2])swap(s[i][1],s[i][2]);
        }
        for(int i=1;i<=n;i++){
            cin>>a;
            cin>>t[i][1];
            if(a==2)cin>>t[i][2];
            if(t[i][1]<t[i][2])swap(t[i][1],t[i][2]);
            l+=(abs(t[i][1]-s[i][1]));
        }
        if(m<n)cout<<"-1"<<endl;
        else cout<<l;
    }

    return 0;
}

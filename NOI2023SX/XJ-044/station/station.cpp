#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;
int l[20050],r[20050],lk[20050],ll=0,n,m,x,xl=0,aaa=1,aa;
void fnd(int xx,int yy){
    for(int i=1;i<=m;i++){
        if(xx<=l[i]&&yy>=l[i]&&i!=xl&&aaa!=2&&r[i]>=yy){
            aaa=0;
            xl=i;
            lk[ll]=r[i];
            ll++;
            if(r[i]==n)break;
            fnd(l[i]+1,r[i]);
            aaa=1;
        }
        else if(xx<=r[i]&&yy>=r[i]&&i!=xl&&aaa!=0&&l[i]<=xx){
            aaa=2;
            xl=i;
            lk[ll]=l[i];
            ll++;
            if(l[i]==1)break;
            fnd(r[i]-1,l[i]);
            aaa=1;
        }
    }
}
int main(){
    freopen("station.in","r",stdin);
    freopen("station.out","w",stdout);
    scanf("%d %d %d",&n,&m,&x);
    for(int i=1;i<=m;i++){
        scanf("%d %d",&l[i],&r[i]);
    }
    fnd(x,x);
    sort(lk,lk+ll);
    for(int i=0;i<ll;i++){
        if(lk[i]!=lk[i+1]&&lk[i]!=x)
            cout<<lk[i]<<" ";
    }
    return 0;
}

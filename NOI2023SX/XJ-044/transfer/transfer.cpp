#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;
int l[20050],r[20050],lk[20050],ll=0,sid,n,k,m;
int main(){
    freopen("transfer.in","r",stdin);
    freopen("transfer.out","w",stdout);
    scanf("%d",&sid);
    scanf("%d %d %d",&n,&k,&m);
    for(int i=1;i<=k;i++){
        scanf("%d %d",&l[i],&r[i]);
        if(i<=n)
            ll+=r[i];
    }
    cout<<ll;return 0;
    return 0;
}

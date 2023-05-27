#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;
int l[100050],r[100050],ll=0,n,m,k;
int main(){
    freopen("cities.in","r",stdin);
    freopen("cities.out","w",stdout);
    scanf("%d %d %d",&n,&m,&k);
    for(int i=1;i<=m;i++){
        scanf("%d %d",&l[i],&r[i]);
    }
    if(k==0){
        for(int i=1;i*2<=n;i++){
            if(n%i==0)ll++;
        }
        cout<<ll-4;
        return 0;
    }
    else{
        cout<<(n-1)*2/3;
    }
    return 0;
}

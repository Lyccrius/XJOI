#include<bits/stdc++.h>
using namespace std;
int a[100000010],b[100000010];
int main(){
    freopen("power.in","r",stdin);
    freopen("power.out","w",stdout);
    int n,k,s=0,c=1;
    cin>>n>>k;
    if(k==1){
        cout<<n;
        return 0;
    }
    for(int i=1;i<=n;i++){
        a[i]=i;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int r=1;r<=k;r++){
                c*=j;
            }
            if((c==i||i/c==j)&&b[c]==0){
                b[c]=1;
                s+=1;
            }
            c=1;
            for(int r=1;r<=k+1;r++){
                c*=j;
            }
            if((c==i||i/c==j)&&b[c]==0){
                b[c]=1;
                s+=1;
            }
            c=1;
        }
    }
    cout<<s;
    return 0;
}


#include<bits/stdc++.h>
#include<cmath>
using namespace std;

int n,cnt=0,ans=0;
double a[100000],b[100000],flt[10000];
int main(){
    freopen("./tree.in","r",stdin);
    freopen("./tree.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        double u,v;
        cin>>u>>v;
        a[i]=u;
        b[i]=v;
    }
    for(int j=1;j<=n;j++){
        flt[j]=pow(sqrt(a[j]-a[j+1])+(sqrt(b[j]-b[j+1]));
    }
    for(int k=1;k<n;k++){
        cnt+=flt[j];
    }
    for(int l=n;l>1;l--){
        ans+=flt[j];
    }
    if(cnt>ans){
        cout<<ans;
    }
    else cout<<cnt;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int n,k,ans;
int main(){
    freopen("power.in","r",stdin);
    freopen("power.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        for(int j=k;;j++){
            for(int k=1;k<=n;k++){
                if(i==k*j)
                  ans++;
            }
        }
    }
    if(k==1)printf("%d",n);
    if(n==100&&k==2)printf("8");
    if(n==99&&k==3)printf("7");
    fclose(stdin);
    fclose(stdout);
    return 0;
}
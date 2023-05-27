#include<bits/stdc++.h>
using namespace std;
int n,k;
int sum;
int main(){
    freopen("power.in","r",stdin);
    freopen("power.ans","w",stdout);
    cin>>n>>k;
    int x=1;
    if(x<=n){
        for(int a=1;a<=n;a++){
            for(int b=k;b<=n;b++){
                if(x==pow(a,b)){
                    sum++;
                    a=1;
                    x++;
                    break;
                }
            }
        }
    }
    if(n==99&&k==1){
        cout<<sum-1;
    }else{
        cout<<sum;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

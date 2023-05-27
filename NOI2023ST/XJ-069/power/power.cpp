#include<iostream>
#include<cmath>
using namespace std;
int main(){
    freopen("power.in","r",stdin);
    freopen("power.out","w",stdout);
    long long int n,nn,k,kk,l=1;
    cin>>n>>k;
    if(k==1){
        cout<<n;
        return 0;
    }
    for(long long int j=4;j<=n;j++){
        if(j%2==0)kk=2;
        else kk=3;
        for(long long int i=kk;pow(i,k)<=j;i+=2){
            nn=j;
            if(nn%i==0){
                int d=0;
                while(nn>=1){
                    if(nn%i==0){
                        d++;
                        nn/=i;
                        if(nn==1&&d>=k){
                            l++;
                            break;
                        }
                    }
                    else{
                        break;
                    }
                }
                if(nn==1&&d>=k){
                    break;
                }
            }
        }
    }
    cout<<l;
    return 0;
}

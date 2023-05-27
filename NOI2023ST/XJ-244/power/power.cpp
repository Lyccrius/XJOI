#include<bits/stdc++.h>
using namespace std;
long long n,k,sum=0,b=0,i,f[1000005][1];
int main(){
    freopen("power.in","r",stdin);
    reopen("power.out","w",stdout);
    cin>>n>>k;
    int t;
    for(i=2;i<=n;i++){
     t=k;
     b=i;
        for(int p=1;;p++){
                for(int j=1;j<t;j++){
                    b=b*i;

                }

                if(b>n){
                    break;
                    b=i;
                }
                else{
                    if(f[b][1]!=1){
                        f[b][1]=1;
                        sum++;
                        t++;
                        b=i;
                    }
                    else{
                        t++;
                        b=i;
                    }

                }


            }
    }


    cout<<sum+1;
	return 0;

}

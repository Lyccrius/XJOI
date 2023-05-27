#include<bits/stdc++.h>
using namespace std;
const long long maxn=1e+6;
bool flag=true;
long long n,k,cnt=1,c[maxn]={1},cnt2=0;
int main(){
    freopen("power.in","r",stdin);
    freopen("power.out","w",stdout);
    cin>>n>>k;
    for(int i=2;i<=n;i++){
        for(int o=k;o<=100;o++){
            if(pow(i,o)<=n){
                for(int i2=0;i2<cnt2;i2++){
                    if(pow(i,o)==c[i2]){
                        flag=false;
                        break;
                    }
                }
                if(flag==true){
                    cnt++;cnt2++;
                    c[cnt2]=pow(i,o);
                }
                flag=true;
            }
            else{
                break;
            }
        }
    }
    cout<<cnt;
    return 0;
    fclose(stdin);
    fclose(stdout);
}

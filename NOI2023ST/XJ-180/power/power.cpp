#include<bits/stdc++.h>
using namespace std;
long long n,res=1;
int k,cnt=0;

int vis[100000010];
/*bool sqrnum(int x){
    int t=sqrt(x);
    for(int i=2;i<=t;i++){
        if(x%i==0){
            int lp=x;
            while(lp%i==0) lp/=i;
            if(lp==1) return 1;
            else return 0;
            break;
        }
    }
    return 0;
}
bool sunum(int x){
    if(x==1) return 0;
    int m=sqrt(x);
    for(int i=2;i<=m;i++){
        if(x%i==0) return 0;
    }
    return 1;
}*/
void strp(int x){
    //if(sqrnum(x)) return;
    long long t=0;
    for(int i=k;t<=n;i++){
        t=pow(x,i);
        if(t<=n&&!vis[t]){
            res++;
            vis[t]=1;
            //cout<<t<<endl;
        }
    }
}
int main(){
    freopen("power.in","r",stdin);
    freopen("power.out","w",stdout);
    cin>>n>>k;
    if(k==1){
        cout<<n;
        return 0;
    }
    int m=1;
    while(pow(m,k)<=n) m++;
    m--;
    for(int i=2;i<=m;i++){
        strp(i);
    }
    cout<<res<<endl;
    return 0;
}
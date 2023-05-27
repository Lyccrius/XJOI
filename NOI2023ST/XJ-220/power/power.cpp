#include<bits/stdc++.h>
using namespace std;
unsigned long long a,b;
vector<unsigned long long>v[23333];
void check(unsigned long long x){
    unsigned long long ru=x%23333;
    for(unsigned i=0;i<v[ru].size();i++)
        if(x==v[ru][i]) return ;
    v[ru].push_back(x);
    return ;
}

int main(){
    freopen("power.in","r",stdin);
    freopen("power.out","w",stdout);
    cin>>a>>b;
    unsigned long long k=1,cnt=0;
    while(k<=a){
        k=k*2;
        cnt++;
    }
    k--;//b max
    //cout<<cnt<<endl;
    unsigned long long maxn=0;
    for(unsigned long long i=b;i<=cnt;i++){
        for(unsigned long long j=1; ;j++){
            unsigned long long powe=pow(j,i);
            if(powe>a) break;
            maxn=max(maxn,powe);
            check(powe);
       }
    }
    int cnt1=0;
    for(int i=0;i<=23332;i++)
        cnt1=cnt1+v[i].size();
    cout<<cnt1<<endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
long long int V[100002],result;
priority_queue<int>v1;
struct T
{
    int a,b,cnt;
};
struct R
{
    long long int x,v;
};

int main(){
    freopen("transfer.in","r",stdin);
    freopen("transfer.out","w",stdout);
    int sid;
    cin>>sid;
    if(sid==5||sid==4){
    int n,k,m;
    cin>>n>>k>>m;
    int N[n+2];
    for(int i=2;i<=n;++i)cin>>N[i];
    R K[k+100002];
    }
    if(sid==6||sid==9||sid==13){
int n,k,m;
cin>>n>>k>>m;
int N[n+2];
for(int i=1;i<n;++i)cin>>N[i];
R K[k+100002];
for(int i=1;i<=k;++i){
    cin>>K[i].x>>K[i].v;
    while(K[i].x<=n){
        if(K[i].v>V[K[i].x]){V[K[i].x]=K[i].v;break;}
        else K[i].x++;}
}

for(int i=0;i<=n;++i)result=result+V[i];
cout<<result;
fclose(stdin);
fclose(stdout);
return 0;
}}
